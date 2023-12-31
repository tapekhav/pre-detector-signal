#ifndef PRE_DETECTOR_SIGNAL_QT_MAIN_WINDOW_CLASS_H
#define PRE_DETECTOR_SIGNAL_QT_MAIN_WINDOW_CLASS_H

#include <memory>

#include <QMainWindow>
#include <QtCharts/QLineSeries>

#include <qt_plotter.h>
#include <generate_signal.h>
#include <qt_plotter_controller.h>

class QClassMainWindow final : public QMainWindow
{
Q_OBJECT
public:
    explicit QClassMainWindow(QWidget *parent = nullptr);

    void setQPlotter();

    void setPlotter(const QSize& size);

    ~QClassMainWindow() final = default;
private:
    std::unique_ptr<QPlotter> _qt_plotter;
};

#endif // PRE_DETECTOR_SIGNAL_QT_MAIN_WINDOW_CLASS_H
