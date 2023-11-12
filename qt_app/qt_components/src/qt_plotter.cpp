#include <qt_plotter.h>
#include <ui_qt_plotter.h>

#include <QVBoxLayout>

#include <qt_coordinate_tool_tip.h>

QtPlotter::QtPlotter(const QVector<QPair<double, double>>& series_data,
                     const QVector<QPair<double, double>>& init_signal_data,
                     QWidget *parent)
                        : QWidget(parent),
                          _ui(new Ui::QtPlotter)
{
    _ui->setupUi(this);

    setPlotter(series_data, init_signal_data);

    setRanges(series_data);
    setToolTip();

    connect(_ui->plotter, &QCustomPlot::mouseMove, this, &QtPlotter::onMouseMove);

    _ui->plotter->replot();
}

void QtPlotter::setSeries(const QVector<QPair<double, double>>& series, int num_graph)
{
    QVector<double> x_data, y_data;

    for (const auto& pair : series)
    {
        x_data.append(pair.first);
        y_data.append(pair.second);
    }

    _ui->plotter->graph(num_graph)->setData(x_data, y_data);
    _ui->plotter->replot();
}

void QtPlotter::addToSeries(double x, double y, int num_graph)
{
    _ui->plotter->graph(num_graph)->addData(x, y);
    _ui->plotter->replot();
}

void QtPlotter::setRanges(const QVector<QPair<double, double>>& series_data)
{
    double min_x = std::numeric_limits<double>::max();
    double max_x = std::numeric_limits<double>::min();
    double min_y = std::numeric_limits<double>::max();
    double max_y = std::numeric_limits<double>::min();

    for (const auto& pair : series_data)
    {
        min_x = std::min(min_x, pair.first);
        max_x = std::max(max_x, pair.first);
        min_y = std::min(min_y, pair.second);
        max_y = std::max(max_y, pair.second);
    }

    const double padding_x = 0.1 * (max_x - min_x);
    const double padding_y = 0.1 * (max_y - min_y);

    QPair<double, double> x_range(min_x - padding_x, max_x + padding_x);
    QPair<double, double> y_range(min_y - padding_y, max_y + padding_y);

    _ui->plotter->xAxis->setRange(x_range.first, x_range.second);
    _ui->plotter->yAxis->setRange(y_range.first, y_range.second);
}

void QtPlotter::onMouseMove(QMouseEvent *event)
{
    double x = _ui->plotter->xAxis->pixelToCoord(event->pos().x());
    double y1 = _ui->plotter->yAxis->pixelToCoord(event->pos().y());
    double y2 = _ui->plotter->graph(1)->data()->findBegin(x)->value;

    _tool_tip->setCoordinates(x, y1, y2);
    _tool_tip->move(event->globalPos() + QPoint(10, 10));
    _tool_tip->show();
}


void QtPlotter::setToolTip()
{
    _tool_tip = new CoordinateToolTip(_ui->plotter);
}

void QtPlotter::setPlotter(const QVector<QPair<double, double>>& series_data,
                           const QVector<QPair<double, double>>& init_signal_data)
{
    _ui->plotter->addGraph();
    _ui->plotter->addGraph();

    _ui->plotter->graph(0)->setPen(QPen(Qt::blue));
    _ui->plotter->graph(1)->setPen(QPen(Qt::red));

    setSeries(series_data, 0);
    setSeries(init_signal_data, 1);

    _ui->plotter->xAxis->setLabel("time");
    _ui->plotter->yAxis->setLabel("value");
}

QtPlotter::~QtPlotter()
{
    delete _ui;
}
