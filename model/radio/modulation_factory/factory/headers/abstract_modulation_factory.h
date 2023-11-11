#ifndef PRE_DETECTOR_SIGNAL_ABSTRACT_MODULATION_FACTORY_H
#define PRE_DETECTOR_SIGNAL_ABSTRACT_MODULATION_FACTORY_H

#include <memory>

#include <modulation_interface.h>
#include <demodulation_interface.h>

template<class T, class U>
class AbstractModulationFactory
{
public:
    [[nodiscard]] virtual std::unique_ptr<IModulation<T, U>> createModulationProduct() const = 0;
    [[nodiscard]] virtual std::unique_ptr<IDemodulation<U, T>> createDemodulationProduct() const = 0;

    virtual ~AbstractModulationFactory() = default;
};

#endif //PRE_DETECTOR_SIGNAL_ABSTRACT_MODULATION_FACTORY_H
