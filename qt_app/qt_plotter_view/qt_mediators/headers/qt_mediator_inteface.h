#ifndef PRE_DETECTOR_SIGNAL_QT_COMPONENT_MDEIATOR_H
#define PRE_DETECTOR_SIGNAL_QT_COMPONENT_MDEIATOR_H

#include <memory>

class QBaseComponent;

class IQtMediator
{
public:
    virtual void notify(std::unique_ptr<QBaseComponent> sender, const QString& message) const = 0;
    virtual ~IQtMediator() = default;
};

#endif //PRE_DETECTOR_SIGNAL_QT_COMPONENT_MDEIATOR_H
