#ifndef PRE_DETECTOR_SIGNAL_QT_PLOTTER_MEDIATOR_H
#define PRE_DETECTOR_SIGNAL_QT_PLOTTER_MEDIATOR_H

#include <qt_base_component.h>

class QPlotter;
class QCoordinateToolTip;

class QtPlotterMediator final : public IQtMediator
{
public:
    QtPlotterMediator(std::unique_ptr<QCoordinateToolTip>& tooltip, std::unique_ptr<QPlotter>& plotter);
    void notify(std::unique_ptr<QBaseComponent> sender, const QString& message) const final;

    ~QtPlotterMediator() final = default;
private:
    std::unique_ptr<QCoordinateToolTip> _tooltip;
    std::unique_ptr<QPlotter> _plotter;

};

#endif //PRE_DETECTOR_SIGNAL_QT_PLOTTER_MEDIATOR_H
