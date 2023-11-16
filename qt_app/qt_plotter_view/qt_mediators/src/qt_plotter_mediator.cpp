#include <qt_plotter_mediator.h>

#include <qt_plotter.h>
#include <qt_coordinate_tool_tip.h>

QtPlotterMediator::QtPlotterMediator(std::unique_ptr<QCoordinateToolTip>& tooltip,
                                     std::unique_ptr<QPlotter>& plotter)
                                     : _tooltip(std::move(tooltip)),
                                       _plotter(std::move(plotter)) {}

void QtPlotterMediator::notify(std::unique_ptr<QBaseComponent> sender, const QString& event) const
{

}
