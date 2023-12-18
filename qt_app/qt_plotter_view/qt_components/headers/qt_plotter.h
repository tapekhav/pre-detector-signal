#ifndef PRE_DETECTOR_SIGNAL_QT_PLOTTER_H
#define PRE_DETECTOR_SIGNAL_QT_PLOTTER_H

#include <qt_plotter_controller.h>
#include <QWidget>
#include <QVector>
#include <QPair>

#include <memory>
#include <qcustomplot.h>

class QCoordinateToolTip;

QT_BEGIN_NAMESPACE
namespace Ui { class QPlotter; }
QT_END_NAMESPACE

class QPlotter final : public QWidget
{
    Q_OBJECT
public:
    explicit QPlotter(QWidget *parent = nullptr);
    ~QPlotter() final = default;

    void setSeries(const Interval& time);

    void setRanges(const QVector<QPair<double, double>>& series_data);

    void setPlotter(const QVector<QPair<double, double>>& series_data,
                    const QVector<QPair<double, double>>& init_signal_data);

signals:
    void timeChanged(Interval time);
private slots:
    void timeOnChanged(const Interval& time);

    void onMouseMove(QMouseEvent *event);
    void sendData();
private:
    std::unique_ptr<Ui::QPlotter> _ui;
    std::unique_ptr<QCoordinateToolTip> _tool_tip;

    std::unique_ptr<QPlotterController> _controller;

    Interval _time;
};


#endif // PRE_DETECTOR_SIGNAL_QT_PLOTTER_H
