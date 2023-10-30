#ifndef PRE_DETECTOR_SIGNAL_QT_MAIN_WINDOW_CLASS_H
#define PRE_DETECTOR_SIGNAL_QT_MAIN_WINDOW_CLASS_H

#include <memory>

#include <QMainWindow>
#include <QtCharts/QLineSeries>

#include <qt_plotter.h>

class QtClassMainWindow final : public QMainWindow
{
    Q_OBJECT
public:

    explicit QtClassMainWindow(QWidget *parent = nullptr);

    void setQtPlotter(std::unique_ptr<QtPlotter>& qt_plotter);

    void setPlotter(const QSize& size);

    ~QtClassMainWindow() final = default;
private:
    std::unique_ptr<QtPlotter> _qt_plotter;
};


#endif //PRE_DETECTOR_SIGNAL_QT_MAIN_WINDOW_CLASS_H
