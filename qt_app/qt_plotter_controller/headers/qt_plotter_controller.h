#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>
#include <vector>

#include <QObject>
#include <qvector.h>

#include <file_mediator.h>
#include <generate_signal.h>

class QPlotterController final : public QObject
{
    Q_OBJECT
public:
    explicit QPlotterController(const Interval& time_interval,
                                QObject *parent = nullptr);

    ~QPlotterController() final = default;

    [[nodiscard]] inline QVector<double> getInPhase() const { return _in_phase; }
    [[nodiscard]] inline QVector<double> getQuadrature() const { return _quadrature; }
    [[nodiscard]] inline QVector<double> getModulating() const { return _modulating_signal; }
    [[nodiscard]] inline QVector<double> getTimeVector() const { return _time; }
public slots:
    void updateVectors(const Interval& time_interval);
private:
    std::shared_ptr<FileReader> _file_reader;
    std::shared_ptr<BinaryFileManager> _file_manager;
    std::shared_ptr<ModelGenerator> _model_generator;
    std::unique_ptr<FileMediator> _mediator;

    std::unique_ptr<SignalGenerator> _signal_generator;

    QVector<double> _time;

    QVector<double> _in_phase;
    QVector<double> _quadrature;

    QVector<double> _modulating_signal;
};

#endif // CONTROLLER_H
