#ifndef PRE_DETECTOR_SIGNAL_QT_PLOTTER_H
#define PRE_DETECTOR_SIGNAL_QT_PLOTTER_H

#include <QWidget>
#include <QVector>
#include <QPair>
#include <qcustomplot.h>

class CoordinateToolTip;

QT_BEGIN_NAMESPACE
namespace Ui { class QtPlotter; }
QT_END_NAMESPACE

class QtPlotter final : public QWidget
{
Q_OBJECT
public:
    explicit QtPlotter(const QVector<QPair<double, double>>& series_data,
                       const QVector<QPair<double, double>>& init_signal_data,
                       QWidget *parent = nullptr);
    ~QtPlotter() final;

    void setSeries(const QVector<QPair<double, double>>& series, int num_graph);

    void addToSeries(double x, double y, int num_graph);
    void setRanges(const QVector<QPair<double, double>>& series_data);

    void setToolTip();
    void setPlotter(const QVector<QPair<double, double>>& series_data,
                    const QVector<QPair<double, double>>& init_signal_data);

signals:
    void signal();
private slots:
    void onMouseMove(QMouseEvent *event);
private:
    Ui::QtPlotter* _ui;
    CoordinateToolTip* _tool_tip;
};


#endif //PRE_DETECTOR_SIGNAL_QT_PLOTTER_H
