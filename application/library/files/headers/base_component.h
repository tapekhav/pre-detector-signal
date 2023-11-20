#ifndef PRE_DETECTOR_SIGNAL_BASE_COMPONENT_H
#define PRE_DETECTOR_SIGNAL_BASE_COMPONENT_H

#include <interface_mediator.h>

#include <utility>

class BaseComponent
{
public:
    explicit BaseComponent(std::shared_ptr<IMediator> mediator = nullptr) : _mediator(std::move(mediator)) {}
    void set_mediator(std::shared_ptr<IMediator> mediator) { this->_mediator = std::move(mediator); }
protected:
    std::shared_ptr<IMediator> _mediator;
};

#endif //PRE_DETECTOR_SIGNAL_BASE_COMPONENT_H
