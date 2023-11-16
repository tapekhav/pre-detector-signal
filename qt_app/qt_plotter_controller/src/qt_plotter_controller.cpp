#include <qt_plotter_controller.h>

QPlotterController::QPlotterController(double sample_rate,
                                       const std::vector<bool>& modulating_signal,
                                       std::unique_ptr<IModulation<double, bool>>& modulation,
                                       QObject *parent)
                                       : QObject(parent),
                                         _signal_generator(std::make_unique<SignalGenerator>(
                                                              sample_rate,
                                                              modulating_signal,
                                                              modulation
                                         )
                                       )
{
    updateVectors();
}

void QPlotterController::updateVectors()
{
    auto modulated_signal = _signal_generator->modulateSignal();

    for (const auto& point : modulated_signal)
    {
        _modulated_signal.push_back(point);
    }

    auto modulating_signal = _signal_generator->getModulatingSignal();

    for (const auto& point : modulated_signal)
    {
        _modulated_signal.push_back(point);
    }

    auto time = _signal_generator->getTimeVector();

    for (auto time_point : time)
    {
        _time_vector.push_back(time_point);
    }
}

void QPlotterController::handleButtonClick(double begin, double end, double sample_rate)
{
    qDebug() << begin << " " << end << " " << sample_rate << "\n";
}

QVector<QPair<double, double>> QPlotterController::getModulatingSignal() {
    return QVector<QPair<double, double>>();
}

QVector<QPair<double, double>> QPlotterController::getModulatedSignal()
{

    return QVector<QPair<double, double>>();
}
