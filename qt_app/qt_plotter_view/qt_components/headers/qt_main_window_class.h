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

    void setQtPlotter(std::unique_ptr<QPlotter>& qt_plotter);

    void setPlotter(const QSize& size);

    void setSignals();

    ~QClassMainWindow() final = default;
private:
    QVector<QPair<double, double>> _series_modulated_signal;
    QVector<QPair<double, double>> _series_modulating_signal;

    std::unique_ptr<QPlotter> _qt_plotter;
    // QPlotterController _controller;
};

#endif // PRE_DETECTOR_SIGNAL_QT_MAIN_WINDOW_CLASS_H
