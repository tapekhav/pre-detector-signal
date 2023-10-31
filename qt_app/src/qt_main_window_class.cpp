#include <qt_main_window_class.h>
#include <QVBoxLayout>

QtClassMainWindow::QtClassMainWindow(QWidget *parent) : QMainWindow(parent)
{
    QVector<QPair<int, int>> seriesData;
    seriesData << qMakePair(1, 2) << qMakePair(3, 4) << qMakePair(5, 6) << qMakePair(7, 8);

    _qt_plotter = std::make_unique<QtPlotter>(seriesData, this);

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

void QtClassMainWindow::setSeries(const QVector<QPair<int, int>>& series)
{
    if (_qt_plotter)
    {
        _qt_plotter->setSeries(series);
    }
}

void QtClassMainWindow::addToSeries(int x, int y)
{
    if (_qt_plotter)
    {
        _qt_plotter->addToSeries(x, y);
    }
}
