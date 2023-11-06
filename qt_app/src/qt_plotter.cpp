#include <qt_plotter.h>
#include <QVBoxLayout>

#include <ui_qt_plotter.h>

QtPlotter::QtPlotter(const QVector<QPair<double, double>>& series_data,
                     const QVector<QPair<double, double>>& init_signal_data,
                     QWidget *parent)
                        : QWidget(parent),
                          _ui(new Ui::QtPlotter)
{
    _ui->setupUi(this);

    //auto* layout = new QVBoxLayout(this);
    //layout->addWidget(customPlot);

    _ui->plotter->addGraph();
    _ui->plotter->addGraph();

    _ui->plotter->graph(0)->setPen(QPen(Qt::blue));
    _ui->plotter->graph(1)->setPen(QPen(Qt::red));

    setSeries(series_data, 0);
    setSeries(init_signal_data, 1);

    _ui->plotter->xAxis->setLabel("X");
    _ui->plotter->yAxis->setLabel("Y");

    setRanges(series_data);

    _ui->plotter->replot();
}

void QtPlotter::setSeries(const QVector<QPair<double, double>>& series, int num_graph)
{
    QVector<double> xData, yData;

    for (const auto& pair : series)
    {
        xData.append(pair.first);
        yData.append(pair.second);
    }

    _ui->plotter->graph(num_graph)->setData(xData, yData);
    _ui->plotter->replot();
}

void QtPlotter::addToSeries(double x, double y, int num_graph)
{
    _ui->plotter->graph(num_graph)->addData(x, y);
    _ui->plotter->replot();
}

void QtPlotter::setRanges(const QVector<QPair<double, double>>& series_data)
{
    double minX = std::numeric_limits<double>::max();
    double maxX = std::numeric_limits<double>::min();
    double minY = std::numeric_limits<double>::max();
    double maxY = std::numeric_limits<double>::min();

    for (const auto& pair : series_data)
    {
        minX = std::min(minX, pair.first);
        maxX = std::max(maxX, pair.first);
        minY = std::min(minY, pair.second);
        maxY = std::max(maxY, pair.second);
    }

    const double paddingX = 0.1 * (maxX - minX);
    const double paddingY = 0.1 * (maxY - minY);

    QPair<double, double> xRange(minX - paddingX, maxX + paddingX);
    QPair<double, double> yRange(minY - paddingY, maxY + paddingY);

    _ui->plotter->xAxis->setRange(xRange.first, xRange.second);
    _ui->plotter->yAxis->setRange(yRange.first, yRange.second);
}

QCustomPlot* QtPlotter::getCustomPlot()
{
    return _ui->plotter;
}
