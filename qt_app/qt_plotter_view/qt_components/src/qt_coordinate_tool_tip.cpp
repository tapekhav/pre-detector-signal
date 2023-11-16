#include <qt_coordinate_tool_tip.h>
#include <ui_qt_coordinate_tool_tip.h>


QCoordinateToolTip::QCoordinateToolTip(QWidget *parent)
        : QWidget(parent),
          _ui(new Ui::CoordinateToolTip)
{
    _ui->setupUi(this);

    auto palette = _ui->coordinate_label->palette();
    palette.setColor(QPalette::Window, Qt::white);

    _ui->coordinate_label->setAutoFillBackground(true);
    _ui->coordinate_label->setPalette(palette);

    setWindowFlags(Qt::ToolTip | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_ShowWithoutActivating);
}

QCoordinateToolTip::~QCoordinateToolTip()
{
    delete _ui;
}

void QCoordinateToolTip::setCoordinates(double x, double y1, double y2)
{
    _ui->coordinate_label->setText(QString("X: %1\nY1: %2\nY2: %3").arg(x).arg(y1).arg(y2));
}
