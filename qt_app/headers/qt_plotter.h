#ifndef PRE_DETECTOR_SIGNAL_PLOTTER_H
#define PRE_DETECTOR_SIGNAL_PLOTTER_H

#include <QApplication>
#include <QWidget>
#include <QtCharts/QChartView>

namespace QtCharts
{
    class QChart;
    class QLineSeries;
    class QValueAxis;
}

class QtPlotter : public QWidget
{
    Q_OBJECT
public:
    explicit QtPlotter();

    void setSeries(const std::vector<QPair<int, int>>& series);
    //! optional method
    void setRanges(QPair<int, int> x_range, QPair<int, int> y_range);

    void setChartView();

    inline QtCharts::QChartView* getChartView() { return _chart_view; }
private:
    QtCharts::QChart *_chart;
    QtCharts::QLineSeries *_series;
    QtCharts::QValueAxis *_axis_x;
    QtCharts::QValueAxis *_axis_y;
    QtCharts::QChartView *_chart_view;

};

#endif //PRE_DETECTOR_SIGNAL_PLOTTER_H
