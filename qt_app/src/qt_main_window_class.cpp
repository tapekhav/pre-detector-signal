#include <qt_main_window_class.h>
#include <QVBoxLayout>
#include <qcustomplot.h>

QtClassMainWindow::QtClassMainWindow(QWidget *parent) : QMainWindow(parent)
{
    setSignals();
    _qt_plotter = std::make_unique<QtPlotter>(_series_modulated_signal, _series_modulating_signal, this);

    setQtPlotter(_qt_plotter);
}

void QtClassMainWindow::setQtPlotter(std::unique_ptr<QtPlotter>& qt_plotter)
{
    setPlotter(QSize(800, 600));
    setCentralWidget(qt_plotter.get());
}

void QtClassMainWindow::setPlotter(const QSize& size)
{
    if (_qt_plotter)
    {
        _qt_plotter->setFixedSize(size);
    }
}

void QtClassMainWindow::setSignals()
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
