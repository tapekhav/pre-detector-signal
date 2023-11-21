#ifndef PRE_DETECTOR_SIGNAL_CONSTS_H
#define PRE_DETECTOR_SIGNAL_CONSTS_H

#include <cstdint>
#include <vector>
#include <bitset>
#include <cassert>

using bitset_sequence = std::vector<std::bitset<14>>;

namespace consts
{
    namespace physics
    {
        const double g = 9.81;

        const double L = 0.0065;
        const double H = 1500;

        const double kMajorAxis = 6378137.0;
        const double kMinorAxis = 6356752.3142;
    }

    namespace radio
    {
        const int kSNR = 20;
        const int kNoiseLevel = 8;
        const int kADCSize = 16;
        const int kGainFactorReceiving = 3000;
        const double kStartSignalLevel = 10e6;
        const double kSampleRate = 2.5 * 10e6;
        const double kReferenceADCVoltage = 5.0;

        const int kBroadWidth = 4096;
        const double kTransmitterPower = 1.0;
        const int kGainFactorTransmitting = 10;
        const double kCentralFrequency = 433 * 10e6;
    }
}

struct Interval
{
    inline Interval(double begin, double end, double step)
                    : begin(begin), end(end), step(step) { assert(step >= 0.01 && step <= 0.5); }

    double begin;
    double end;
    double step;
};

#endif //PRE_DETECTOR_SIGNAL_CONSTS_H
