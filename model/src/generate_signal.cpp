#include <generate_signal.h>

#include <map>
#include <functional>

/*
static const std::map<std::type_index, std::function<void(IModulation<double, bool>*)>> type_map =
{
        { std::type_index(typeid(BPSKModulation)), [](std::unique_ptr<IModulation<double, bool> modulation)
            {
                modulation = dynamic_cast<BPSKModulation*>(modulation);
            }
        }
}; */

SignalGenerator::SignalGenerator(const Interval& time,
                                 const std::vector<bool>& modulating_signal,
                                 std::unique_ptr<IModulation<double, bool>>& modulation)
                                 : _modulation(std::move(modulation)),
                                   _modulating_signal(modulating_signal)
{
    setTimeInterval(time);
}

SignalGenerator::SignalGenerator(const SignalGenerator &other)
{
    _time_vector = other._time_vector;
    _modulating_signal = other._modulating_signal;
    tryToSetModulation(other._modulation);
}

SignalGenerator::SignalGenerator(SignalGenerator&& other) noexcept
                                 : _time_vector(std::move(other._time_vector)),
                                   _modulating_signal(std::move(other._modulating_signal)),
                                   _modulation(std::move(other._modulation)) {}

void SignalGenerator::tryToSetModulation(const std::unique_ptr<IModulation<double, bool>>& other_modulation)
{
    if (auto modulation = dynamic_cast<BPSKModulation*>(other_modulation.get()))
    {
        _modulation = std::make_unique<BPSKModulation>(*modulation);
    }
    else
    {
        // some logic
    }
}

void SignalGenerator::setTimeInterval(const Interval &time)
{
    for (size_t i = time.begin; i < time.end; i += time.step)
    {
        _time_vector.push_back(time.begin + static_cast<double>(i) / time.step);
    }
}

