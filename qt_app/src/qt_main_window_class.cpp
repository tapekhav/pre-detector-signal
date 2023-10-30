#include <qt_main_window_class.h>
#include <QVBoxLayout>

QtClassMainWindow::QtClassMainWindow(QWidget *parent) : QMainWindow(parent)
{
    _qt_plotter = std::make_unique<QtPlotter>();

    auto* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    auto* layout = new QVBoxLayout(centralWidget);
    layout->addWidget(_qt_plotter->getChartView());
    centralWidget->setLayout(layout);
}

void QtClassMainWindow::setQtPlotter(std::unique_ptr<QtPlotter>& qt_plotter)
{
    _qt_plotter = std::move(qt_plotter);
}

void QtClassMainWindow::setPlotter(const QSize& size)
{
    _qt_plotter->resize(size);
}
