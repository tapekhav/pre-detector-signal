#ifndef PRE_DETECTOR_SIGNAL_INTERFACE_MEDIATOR_H
#define PRE_DETECTOR_SIGNAL_INTERFACE_MEDIATOR_H

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
