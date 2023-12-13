#include "consts.h"
#include <qt_main_window_class.h>

#include <QVBoxLayout>

#include <qcustomplot.h>
#include <qt_plotter_controller.h>

QClassMainWindow::QClassMainWindow(QWidget *parent)
                                   : QMainWindow(parent),
                                     _qt_plotter(nullptr)
{
    _qt_plotter = std::make_unique<QPlotter>(this);

    setPlotter(QSize(400, 300));

    // connect(&_signal_generator, &SignalGenerator::someSignal, &_controller, &QPlotterController::updatePlot);

    setSignals();
    // emit _controller.updatePlot();
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
    
}
