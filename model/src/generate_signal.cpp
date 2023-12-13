#include <consts.h>
#include <cstddef>
#include <generate_signal.h>

#include <map>
#include <functional>

#include <utility>

SignalGenerator::SignalGenerator(std::vector<bool> modulating_signal)
                                 : _modulating_signal(std::move(modulating_signal))
{    
    BPSKModulationFactory factory(
        1,
        consts::radio::kSampleRate, 
        consts::radio::kCentralFrequency,
        consts::radio::kBroadWidth 
    );

    _modulation = std::move(factory.createModulationProduct());
}

void SignalGenerator::swap(SignalGenerator& other)
{
    std::swap(_time_vector, other._time_vector);
    std::swap(_modulating_signal, other._modulating_signal);
    std::swap(_modulation, other._modulation);
}

SignalGenerator::SignalGenerator(SignalGenerator&& other) noexcept
                                 : _time_vector(std::move(other._time_vector)),
                                   _modulating_signal(std::move(other._modulating_signal)),
                                   _modulation(std::move(other._modulation)) {}

void SignalGenerator::setTimeInterval(const Interval &time_interval)
{
    for (double i = time_interval.begin; i < time_interval.end; i += time_interval.step)
    {
        _time_vector.push_back(time_interval.begin + static_cast<double>(i) / time_interval.step);
    }
}

void SignalGenerator::modulateSignal(const Interval &time_interval)
{
    setTimeInterval(time_interval);
    _modulation->modulate(_modulating_signal);

    _in_phase = std::move(_modulation->getInPhase());
    _quadrature = std::move(_modulation->getQuadrature());
}

