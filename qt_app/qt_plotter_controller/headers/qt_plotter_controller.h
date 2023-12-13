#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <memory>

#include <models_mediator.h>
#include <generate_signal.h>
#include <qvector.h>
#include <vector>

template <class T> 
using time_vec = QVector<QPair<T, double>>; 


class QPlotterController final : public QObject
{
    Q_OBJECT
public:
    explicit QPlotterController(const Interval& time_interval,
                                QObject *parent = nullptr);

    ~QPlotterController() final = default;

    [[nodiscard]] inline time_vec<double> getInPhase() const { return _in_phase; }
    [[nodiscard]] inline time_vec<double> getQuadrature() const { return _quadrature; }
    [[nodiscard]] inline time_vec<bool> getModulating() const { return _modulating_signal; }
public slots:
    void updateVectors(const Interval& time_interval);
    void handleButtonClick(double begin, double end, double sample_rate);
private:
    std::shared_ptr<FileReader> _file_reader;
    std::shared_ptr<BinaryFileManager> _file_manager;
    std::shared_ptr<ModelGenerator> _model_generator;
    std::unique_ptr<ModelsMediator> _mediator;

    std::unique_ptr<SignalGenerator> _signal_generator;

    time_vec<double> _in_phase;
    time_vec<double> _quadrature;

    time_vec<bool> _modulating_signal;
};

#endif // CONTROLLER_H
