#include <qt_main_window_class.h>
#include <qt_plotter.h>

/*
void ahah()
{
    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();
}

*/
void QtClassMainWindow::setPlotter()
{
    _window.setCentralWidget(chartView);
    _window.resize(400, 300);
    _window.show();
}
