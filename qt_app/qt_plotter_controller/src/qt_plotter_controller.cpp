#include <qt_plotter_controller.h>
#include <config_parser.h>

QPlotterController::QPlotterController(const Interval& time_interval,
                                       std::unique_ptr<IModulation<double, bool>>& modulation,
                                       QObject *parent)
                                       : QObject(parent)
{
    ConfigParser parser;
    parser.setData();

    //! Поменять на уже смодулированные
    _model_generator = std::make_unique<ModelGenerator>(parser.getModel());
    _signal_generator = std::make_unique<SignalGenerator>(
            _model_generator->generateModel(time_interval),
            modulation
    );

    updateVectors(time_interval);
}

void QPlotterController::updateVectors(const Interval& time_interval)
{
    QVector<double> time_vector;
    for (double time_point = time_interval.begin; time_point < time_interval.end; time_point += time_interval.step)
    {
        time_vector.push_back(time_point);
    }

    auto modulated_signal = _signal_generator->modulateSignal(time_interval);
    for (int i = 0; i < modulated_signal.size(); ++i)
    {
        _modulated_signal.push_back({modulated_signal[i], time_vector[i]});
    }

    auto modulating_signal = _signal_generator->getModulatingSignal();
    for (int i = 0; i < modulating_signal.size(); ++i)
    {
        _modulating_signal.push_back({modulated_signal[i], time_vector[i]});
    }

}

void QPlotterController::handleButtonClick(double begin, double end, double sample_rate)
{
    qDebug() << begin << " " << end << " " << sample_rate << "\n";
}
