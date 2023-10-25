#ifndef PRE_DETECTOR_SIGNAL_QT_MAIN_WINDOW_CLASS_H
#define PRE_DETECTOR_SIGNAL_QT_MAIN_WINDOW_CLASS_H

#include <QMainWindow>

class QtPlotter;

class QtClassMainWindow
{
public:
    void setPlotter();
private:
    QtPlotter* _qt_plotter;
    QMainWindow _window;
};

/*
void ahah()
{
    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();
}

*/

#endif //PRE_DETECTOR_SIGNAL_QT_MAIN_WINDOW_CLASS_H
