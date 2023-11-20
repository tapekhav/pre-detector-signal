#ifndef PRE_DETECTOR_SIGNAL_INTERFACE_MEDIATOR_H
#define PRE_DETECTOR_SIGNAL_INTERFACE_MEDIATOR_H

#ifdef GTEST_SKIP_MEDIATOR
#define MEDIATE(event)
#else
#define MEDIATE(event) this->_mediator->notify(event)
#endif


#include <memory>

class BaseComponent;

enum class EventType
{
    GenerateModel,
    WriteToFile,
    ReadFromFile
};

class IMediator
{
public:
    virtual void notify(EventType event) const = 0;

    virtual ~IMediator() = default;
};

#endif //PRE_DETECTOR_SIGNAL_INTERFACE_MEDIATOR_H
