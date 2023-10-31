#ifndef PRE_DETECTOR_SIGNAL_QT_PLOTTER_H
#define PRE_DETECTOR_SIGNAL_QT_PLOTTER_H

#include <QWidget>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChartView>
#include <QVector>
#include <QPair>


QT_BEGIN_NAMESPACE
namespace Ui { class QtPlotter; }
QT_END_NAMESPACE

class QtPlotter : public QWidget
{
    Q_OBJECT
public:
    explicit QtPlotter(QWidget *parent = nullptr);
    ~QtPlotter() override;

    void setSeries(const QVector<QPair<int, int>>& series);
    void addToSeries(int x, int y);
    void setRanges(QPair<int, int> x_range, QPair<int, int> y_range);
    QtCharts::QChartView* getChartView();
signals:
    void signal();
public slots:
    void slot() {};
private:
    Ui::QtPlotter *ui;
    QtCharts::QChart* _chart;
    QtCharts::QLineSeries* _series;
    QtCharts::QValueAxis* _axis_x;
    QtCharts::QValueAxis* _axis_y;
    QtCharts::QChartView* _chart_view;
};


#endif //PRE_DETECTOR_SIGNAL_QT_PLOTTER_H
