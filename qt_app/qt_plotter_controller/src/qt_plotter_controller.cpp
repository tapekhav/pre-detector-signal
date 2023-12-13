#include <qt_plotter_controller.h>

#include <memory>
#include <thread>

#include <config_parser.h>
#include <generate_signal.h>

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
    
    _model_generator->generateModel(time_interval);
    _signal_generator = std::make_unique<SignalGenerator>(_mediator->getInfoBits());

    updateVectors(time_interval);
}

void QPlotterController::updateVectors(const Interval& time_interval)
{
    QVector<double> time_vector;
    for (double time_point = time_interval.begin; time_point < time_interval.end; time_point += time_interval.step)
    {
        time_vector.push_back(time_point);
    }

    _signal_generator->modulateSignal(time_interval);

    std::thread modulated(
    [&]()
        {
            auto in_phase = _signal_generator->getInPhase();
            auto quadrature = _signal_generator->getQuadrature();

            for (int i = 0; i < in_phase.size(); ++i)
            {
                _in_phase.push_back({in_phase[i], time_vector[i]});
                _quadrature.push_back({quadrature[i], time_vector[i]});
            }
        }
    );

    auto modulating_signal = _signal_generator->getModulatingSignal();
    for (int i = 0; i < modulating_signal.size(); ++i)
    {
        _modulating_signal.push_back({modulating_signal[i], time_vector[i]});
    }

    modulated.join();
}
