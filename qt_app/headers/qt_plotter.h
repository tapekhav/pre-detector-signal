#ifndef PRE_DETECTOR_SIGNAL_QT_PLOTTER_H
#define PRE_DETECTOR_SIGNAL_QT_PLOTTER_H

#include <QWidget>
#include <QVector>
#include <QPair>
#include <qcustomplot.h>

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
    ~QtPlotter() final = default;

    void setSeries(const QVector<QPair<double, double>>& series, int num_graph);

    void addToSeries(double x, double y, int num_graph);
    void setRanges(const QVector<QPair<double, double>>& series_data);
    QCustomPlot* getCustomPlot();
signals:
    void signal();
public slots:
    void slot() {};
private:
    QCustomPlot* customPlot;
    Ui::QtPlotter* _ui;
};


#endif //PRE_DETECTOR_SIGNAL_QT_PLOTTER_H
