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

SignalGenerator::SignalGenerator(double sample_rate,
                                 const std::vector<double>& modulating_signal,
                                 std::unique_ptr<IModulation<double, bool>>& modulation)
                                 : _modulation(std::move(modulation))
{
    for (size_t i = 0; i < modulating_signal.size(); ++i)
    {
        _time_vector.push_back(static_cast<double>(i) / sample_rate);
    }
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

