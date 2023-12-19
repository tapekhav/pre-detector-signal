#include <qt_plotter_controller.h>

#include <memory>
#include <thread>

#include <file_reader.h>
#include <qt_utilities.h>
#include <config_parser.h>
#include <generate_signal.h>
#include <binary_file_manager.h>


//! TODO: write path to file
const static std::string kPath = "tmp.txt";

QPlotterController::QPlotterController(const Interval& time_interval,
                                       QObject *parent)
                                       : QObject(parent)
{
    ConfigParser parser;
    parser.setData();

    _model_generator = std::make_shared<ModelGenerator>(parser.getModel());
    _file_reader = std::make_shared<FileReader>(kPath);
    _file_manager = std::make_shared<BinaryFileManager>(kPath);

    _mediator = std::make_unique<FileMediator>(
        _file_reader, 
        _file_manager, 
        _model_generator
    );

    updateVectors(time_interval);
}

void QPlotterController::updateVectors(const Interval& time_interval)
{
    _model_generator->generateModel(time_interval);

    auto modulating_signal = _mediator->getInfoBits(); 
    _signal_generator = std::make_unique<SignalGenerator>(modulating_signal);

    std::thread modulated(
        [&]()
        {        
            _signal_generator->modulateSignal(time_interval);

            _in_phase = qt::toQVector(_signal_generator->getInPhase());
            _quadrature = qt::toQVector(_signal_generator->getQuadrature());
        }
    );

    int k = 0;
    for (double time_point = time_interval.begin; time_point < time_interval.end; time_point += time_interval.step)
    {
        _modulating_signal[k] = modulating_signal[k++] ? 1.0 : 0.0;
        _time.push_back(time_point);
    }
    modulated.join();
}
