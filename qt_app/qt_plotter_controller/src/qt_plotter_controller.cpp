#include <qt_plotter_controller.h>

#include <memory>
#include <qvector.h>
#include <thread>

#include <file_reader.h>
#include <config_parser.h>
#include <generate_signal.h>
#include <binary_file_manager.h>


QPlotterController::QPlotterController(const Interval& time_interval,
                                       QObject *parent)
                                       : QObject(parent)
{
    ConfigParser parser;
    parser.setData();

    _model_generator = std::make_shared<ModelGenerator>(parser.getModel());
    _file_manager = std::make_shared<BinaryFileManager>();
    _file_reader = std::make_shared<FileReader>();

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

            auto in_phase = _signal_generator->getInPhase();
            _in_phase = QVector<double>(in_phase.cbegin(), in_phase.cend());

            auto quadrature = _signal_generator->getQuadrature();
            _quadrature = QVector<double>(quadrature.cbegin(), quadrature.cend());
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
