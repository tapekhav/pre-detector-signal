#include <qt_main_window_class.h>

#include <QVBoxLayout>

#include <qcustomplot.h>
#include <qt_plotter_controller.h>

QClassMainWindow::QClassMainWindow(QWidget *parent)
                                   : QMainWindow(parent),
                                     _qt_plotter(nullptr),
                                     _controller(&_signal_generator)
{
    _qt_plotter = std::make_unique<QPlotter>(_series_modulated_signal, _series_modulating_signal, this);

    setPlotter(QSize(400, 300));

    connect(&_signal_generator, &SignalGenerator::someSignal, &_controller, &QPlotterController::updatePlot);

    setSignals();
    emit _controller.updatePlot();
}


void QClassMainWindow::setQtPlotter(std::unique_ptr<QPlotter>& qt_plotter)
{
    setPlotter(QSize(800, 600));
    setCentralWidget(qt_plotter.get());
}

void QClassMainWindow::setPlotter(const QSize& size)
{
    if (_qt_plotter)
    {
        _qt_plotter->setFixedSize(size);
    }
}

void QClassMainWindow::setSignals()
{
    auto values = _signal_generator.modulateSignal();
    auto times = _signal_generator.getTimeVector();
    auto initial_values = _signal_generator.getModulatingSignal();

    for (size_t i = 0; i < values.size(); ++i)
    {
        _series_modulated_signal << qMakePair(times[i], values[i]);
        _series_modulating_signal << qMakePair(times[i], initial_values[i]);
    }
}
