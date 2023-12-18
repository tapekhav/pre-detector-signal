#include <qt_plotter.h>

#include <QVBoxLayout>

#include <memory>

#include <ui_qt_plotter.h>
#include <qt_coordinate_tool_tip.h>

QPlotter::QPlotter(QWidget *parent)
                   : QWidget(parent),
                     _ui(std::make_unique<Ui::QPlotter>()),
                     _time({0, 10, 0.5}),
                     _tool_tip(std::make_unique<QCoordinateToolTip>(_ui->plotter)),
                     _controller(std::make_unique<QPlotterController>(_time))
{
    _ui->setupUi(this);
    
    //! TODO: remove magic number
    for (size_t i = 0; i < 3; ++i)
    {
        _ui->plotter->addGraph();
    }

    connect(_ui->plotter, &QCustomPlot::mouseMove, this, &QPlotter::onMouseMove);
    connect(_ui->_apply_button, SIGNAL(clicked()), this, SLOT(sendData()));

    _controller->updateVectors(_time);
}

void QPlotter::setSeries(const Interval& time)
{
    _controller->updateVectors(time);

    auto time_vector = _controller->getTimeVector();

    _ui->plotter->graph(0)->setData(_controller->getInPhase(), time_vector);
    _ui->plotter->graph(1)->setData(_controller->getQuadrature(), time_vector);
    _ui->plotter->graph(2)->setData(_controller->getModulating(), time_vector);

    _ui->plotter->replot();
}

void QPlotter::setRanges(const QVector<QPair<double, double>>& series_data)
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

void QPlotter::onMouseMove(QMouseEvent *event)
{
    double x = _ui->plotter->xAxis->pixelToCoord(event->pos().x());
    double y1 = _ui->plotter->yAxis->pixelToCoord(event->pos().y());
    double y2 = _ui->plotter->graph(1)->data()->findBegin(x)->value;

    _tool_tip->setCoordinates(x, y1, y2);
    _tool_tip->move(event->globalPos() + QPoint(10, 10));
    _tool_tip->show();
}

void QPlotter::sendData()
{
   _time = Interval(_ui->_begin_line_edit->text().toDouble(), 
                    _ui->end_line_edit->text().toDouble(),
                    _ui->step_line_edit->text().toDouble());
}

void QPlotter::setPlotter(const QVector<QPair<double, double>>& series_data,
                          const QVector<QPair<double, double>>& init_signal_data)
{
    _ui->plotter->addGraph();
    _ui->plotter->addGraph();

    for (uint32_t i = 0; i < 3; ++i)
    {
        QColor randomColor = QColor::fromRgb(QRandomGenerator::global()->generate());
        _ui->plotter->graph(i)->setPen(QPen(randomColor));
    }

    _ui->plotter->xAxis->setLabel("time");
    _ui->plotter->yAxis->setLabel("value");
}

void QPlotter::timeOnChanged(const Interval& time)
{
    if (!(_time == time))
    {
        _controller->updateVectors(time);
        emit timeChanged(time);
    }
}