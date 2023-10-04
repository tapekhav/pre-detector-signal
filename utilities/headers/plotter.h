#ifndef PRE_DETECTOR_SIGNAL_PLOTTER_H
#define PRE_DETECTOR_SIGNAL_PLOTTER_H

#include <QtWidgets/QApplication>
#include <QWidget>

namespace QtCharts
{
    class QChart;
    class QChartView;
    class QLineSeries;
}


class Plotter : public QWidget
{
    Q_OBJECT
public:
    explicit Plotter(QWidget *parent = nullptr);

    void setTitle(const QString& title);

    void setAxisX(const QString& axis_x, QPair<int, int> range);
    void setAxisY(const QString& axis_y, QPair<int, int> range);
private:
    QtCharts::QChart* _chart;
    QtCharts::QLineSeries* _series;
    QtCharts::QChartView* _chartView;
};


#endif //PRE_DETECTOR_SIGNAL_PLOTTER_H
