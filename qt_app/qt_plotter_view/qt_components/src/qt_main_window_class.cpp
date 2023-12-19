#include <qt_main_window_class.h>

#include <QVBoxLayout>
#include <qcustomplot.h>

#include <qt_plotter_controller.h>

QClassMainWindow::QClassMainWindow(QWidget *parent)
                                   : QMainWindow(parent),
                                     _qt_plotter(std::make_unique<QPlotter>(this))
{
    setQPlotter();
}


void QClassMainWindow::setQPlotter()
{
    setPlotter(QSize(800, 600));
    setCentralWidget(_qt_plotter.get());
}

void QClassMainWindow::setPlotter(const QSize& size)
{
    if (_qt_plotter)
    {
        _qt_plotter->setFixedSize(size);
    }
}
