#include <qt_plotter_mediator.h>

#include <qt_plotter.h>
#include <qt_coordinate_tool_tip.h>

QtPlotterMediator::QtPlotterMediator(std::unique_ptr<CoordinateToolTip>& tooltip,
                                     std::unique_ptr<QtPlotter>& plotter)
                                     : _tooltip(std::move(tooltip)),
                                       _plotter(std::move(plotter)) {}

void QtPlotterMediator::notify(std::unique_ptr<QtBaseComponent> sender, const QString& event) const
{

}
