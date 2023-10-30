#ifndef PRE_DETECTOR_SIGNAL_PLOTTER_H
#define PRE_DETECTOR_SIGNAL_PLOTTER_H

#include <QWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QtCharts/QLineSeries>

class QtPlotter final : public QWidget
{
Q_OBJECT
public:
    QtPlotter(QWidget *parent = nullptr);

    void setSeries(const QVector<QPair<int, int>>& series);
    void addToSeries(int x, int y);
    void setRanges(QPair<int, int> x_range, QPair<int, int> y_range);

    QtCharts::QChartView* getChartView();

private:
    QtCharts::QChart* _chart;
    QtCharts::QLineSeries* _series;
    QtCharts::QValueAxis* _axis_x;
    QtCharts::QValueAxis* _axis_y;
    QtCharts::QChartView* _chart_view;
};

#endif // PRE_DETECTOR_SIGNAL_PLOTTER_H
