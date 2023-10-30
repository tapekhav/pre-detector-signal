#include <qt_plotter.h>
#include <ui_qt_plotter.h>


QtPlotter::QtPlotter(QWidget *parent) : QWidget(parent),
                                        ui(new Ui::QtPlotter),
                                        _chart(new QtCharts::QChart),
                                        _series(new QtCharts::QLineSeries),
                                        _axis_x(new QtCharts::QValueAxis),
                                        _axis_y(new QtCharts::QValueAxis),
                                        _chart_view(new QtCharts::QChartView(_chart))
{
    ui->setupUi(this);

    _chart_view->setRenderHint(QPainter::Antialiasing);
    _chart->addSeries(_series);
    _chart->setAxisX(_axis_x, _series);
    _chart->setAxisY(_axis_y, _series);
}

void QtPlotter::setSeries(const QVector<QPair<int, int>>& series)
{
    _series->clear();
    for (const auto& pair : series)
    {
        _series->append(pair.first, pair.second);
    }
}

void QtPlotter::addToSeries(int x, int y)
{
    _series->append(x, y);
}

void QtPlotter::setRanges(QPair<int, int> x_range, QPair<int, int> y_range)
{
    _axis_x->setRange(x_range.first, x_range.second);
    _axis_y->setRange(y_range.first, y_range.second);
}

QtCharts::QChartView* QtPlotter::getChartView()
{
    return _chart_view;
}

QtPlotter::~QtPlotter()
{
    delete _series;
    delete _chart;
    delete _chart_view;
    delete _axis_x;
    delete _axis_y;
    delete ui;
}
