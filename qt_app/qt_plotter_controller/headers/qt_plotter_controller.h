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
    QPlotterController(double sample_rate,
                       const std::vector<bool>& modulating_signal,
                       std::unique_ptr<IModulation<double, bool>>& modulation,
                       QObject *parent = nullptr
    );

    ~QPlotterController() final = default;

public slots:
    void updateVectors();
    void handleButtonClick(double begin, double end, double sample_rate);

private slots:
    QVector<QPair<double, double>> getModulatedSignal();

    QVector<QPair<double, double>> getModulatingSignal();
private:
    std::unique_ptr<SignalGenerator> _signal_generator;

    QVector<double> _time_vector;
    QVector<double> _modulated_signal;
    QVector<bool> _modulating_signal;
};

#endif // CONTROLLER_H
