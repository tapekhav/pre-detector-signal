#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <memory>

#include <qt_plotter.h>
#include <generate_signal.h>


//! TODO подключить фабрику
class QPlotterController final : public QObject
{
    Q_OBJECT
public:
    QPlotterController(const Interval& time_interval,
                       std::unique_ptr<IModulation<double, bool>>& modulation,
                       QObject *parent = nullptr
    );

    ~QPlotterController() final = default;

public slots:
    void updateVectors(const Interval& time_interval);
    void handleButtonClick(double begin, double end, double sample_rate);
private:
    std::unique_ptr<ModelGenerator> _model_generator;
    std::unique_ptr<SignalGenerator> _signal_generator;

    QVector<QPair<double, double>> _modulated_signal;
    QVector<QPair<bool, double>> _modulating_signal;
};

#endif // CONTROLLER_H
