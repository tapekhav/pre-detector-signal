#include <qt_plotter.h>
#include <ui_qt_plotter.h>
#include <QVBoxLayout>

QtPlotter::QtPlotter(const QVector<QPair<int, int>>& series_data, QWidget *parent)
                                                                  : QWidget(parent),
                                                                    ui(new Ui::QtPlotter),
                                                                    _chart(new QtCharts::QChart),
                                                                    _axis_x(new QtCharts::QValueAxis),
                                                                    _axis_y(new QtCharts::QValueAxis),
                                                                    _chart_view(new QtCharts::QChartView(_chart))
{
    ui->setupUi(this);

    _chart_view->setRenderHint(QPainter::Antialiasing);

    _series = new QtCharts::QLineSeries;
    setSeries(series_data);

    _chart->addSeries(_series);
    _chart->setAxisX(_axis_x, _series);
    _chart->setAxisY(_axis_y, _series);

    auto* layout = new QVBoxLayout;
    layout->addWidget(_chart_view);
    setLayout(layout);
}

void QtPlotter::setSeries(const QVector<QPair<int, int>>& series)
{
    for (const auto& pair : series)
    {
        _series->append(pair.first, pair.second);
    }

    _chart->update();
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
    delete ui;
}
