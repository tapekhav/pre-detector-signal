#ifndef PRE_DETECTOR_SIGNAL_QT_MAIN_WINDOW_CLASS_H
#define PRE_DETECTOR_SIGNAL_QT_MAIN_WINDOW_CLASS_H

#include <memory>

#include <QMainWindow>
#include <QtCharts/QLineSeries>

#include <qt_plotter.h>
#include <generate_signal.h>

class QtClassMainWindow final : public QMainWindow
{
public:

    explicit QtClassMainWindow(QWidget *parent = nullptr);

    void setQtPlotter(std::unique_ptr<QtPlotter>& qt_plotter);

    void setPlotter(const QSize& size);

    void setSignals();

    ~QtClassMainWindow() final = default;
private:
    SignalGenerator _signal_generator;
    QVector<QPair<double, double>> _series_modulated_signal;
    QVector<QPair<double, double>> _series_modulating_signal;

    std::unique_ptr<QtPlotter> _qt_plotter;
};


#endif //PRE_DETECTOR_SIGNAL_QT_MAIN_WINDOW_CLASS_H
