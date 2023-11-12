#ifndef PRE_DETECTOR_SIGNAL_QT_PLOTTER_MEDIATOR_H
#define PRE_DETECTOR_SIGNAL_QT_PLOTTER_MEDIATOR_H

#include <qt_base_component.h>

class QtPlotter;
class CoordinateToolTip;

class QtPlotterMediator final : public IQtMediator
{
public:
    QtPlotterMediator(std::unique_ptr<CoordinateToolTip>& tooltip, std::unique_ptr<QtPlotter>& plotter);
    void notify(std::unique_ptr<QtBaseComponent> sender, const QString& message) const final;

    ~QtPlotterMediator() final = default;
private:
    std::unique_ptr<CoordinateToolTip> _tooltip;
    std::unique_ptr<QtPlotter> _plotter;

};

#endif //PRE_DETECTOR_SIGNAL_QT_PLOTTER_MEDIATOR_H
