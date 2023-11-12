#ifndef PRE_DETECTOR_SIGNAL_BASE_COMPONENT_INTERFACE_H
#define PRE_DETECTOR_SIGNAL_BASE_COMPONENT_INTERFACE_H

#include <QWidget>

#include <qt_mediator_inteface.h>

class QtBaseComponent : public QWidget
{
public:
    explicit QtBaseComponent(std::unique_ptr<IQtMediator>& mediator) : _mediator(std::move(mediator)) {}

    void setMediator(std::unique_ptr<IQtMediator>& mediator) { _mediator = std::move(mediator); }
protected:
    std::unique_ptr<IQtMediator> _mediator;
};

#endif //PRE_DETECTOR_SIGNAL_BASE_COMPONENT_INTERFACE_H
