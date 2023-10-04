#include <plotter.h>

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

Plotter::Plotter(QWidget *parent) : _chart(new QtCharts::QChart()),
                                    _series(new QtCharts::QLineSeries()),
                                    _chartView(new QtCharts::QChartView(parent))
{
    _chart->legend()->hide();
    _chart->createDefaultAxes();
    _chartView->setRenderHint(QPainter::Antialiasing);
}

void Plotter::setTitle(const QString &title)
{
    _chart->setTitle(title);
}

void Plotter::setAxisX(const QString &xAxisName, QPair<int, int> range)
{
    auto *xAxis = new QtCharts::QValueAxis;
    xAxis->setRange(range.first, range.second);
    xAxis->setTitleText(xAxisName);
}

void Plotter::setAxisY(const QString &yAxisName, QPair<int, int> range)
{
    auto *xAxis = new QtCharts::QValueAxis;
    xAxis->setRange(range.first, range.second);
    xAxis->setTitleText(yAxisName);
}
