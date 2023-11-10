#ifndef PRE_DETECTOR_SIGNAL_QT_COORDINATE_TOOL_TIP_H
#define PRE_DETECTOR_SIGNAL_QT_COORDINATE_TOOL_TIP_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class CoordinateToolTip; }
QT_END_NAMESPACE

class CoordinateToolTip final : public QWidget {
    Q_OBJECT

public:
    explicit CoordinateToolTip(QWidget *parent = nullptr);
    ~CoordinateToolTip() final;

    void setCoordinates(double x, double y1, double y2);

private:
    Ui::CoordinateToolTip *_ui;
};


#endif //PRE_DETECTOR_SIGNAL_QT_COORDINATE_TOOL_TIP_H
