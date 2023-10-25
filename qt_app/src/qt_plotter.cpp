#include <qt_plotter.h>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

QtPlotter::QtPlotter() : _chart(new QtCharts::QChart),
                         _series(new QtCharts::QLineSeries),
                         _chart_view(new QtCharts::QChartView),
                         _axis_x(new QtCharts::QValueAxis),
                         _axis_y(new QtCharts::QValueAxis) {}

void QtPlotter::setSeries(const std::vector<QPair<int, int>>& series)
{
    for (const auto& pair : series)
    {
        _series->append(pair.first, pair.second);
    }

    _chart->addSeries(_series);
}

void QtPlotter::setRanges(QPair<int, int> x_range, QPair<int, int> y_range)
{
   _axis_x->setRange(x_range.first, x_range.second);
   _axis_y->setRange(y_range.first, y_range.second);

   _chart->setAxisX(_axis_x, _series);
   _chart->setAxisY(_axis_y, _series);
}

void QtPlotter::setChartView()
{
    auto *chartView = new QtCharts::QChartView(_chart);
    chartView->setRenderHint(QPainter::Antialiasing);
}