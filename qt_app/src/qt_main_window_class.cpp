#include <qt_main_window_class.h>
#include <QVBoxLayout>

QtClassMainWindow::QtClassMainWindow(QWidget *parent) : QMainWindow(parent)
{
    _qt_plotter = std::make_unique<QtPlotter>(this);
    setQtPlotter(_qt_plotter);
}

void QtClassMainWindow::setQtPlotter(std::unique_ptr<QtPlotter>& qt_plotter)
{
    setPlotter(QSize(800, 400));
    setCentralWidget(qt_plotter.get());
}

void QtClassMainWindow::setPlotter(const QSize& size)
{
    if (_qt_plotter)
    {
        _qt_plotter->setFixedSize(size);
    }
}
