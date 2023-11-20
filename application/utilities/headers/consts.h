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
        static const double g = 9.81;

        static const double L = 0.0065;
        static const double H = 1500;

        static const double kMajorAxis = 6378137.0;
        static const double kMinorAxis = 6356752.3142;
    }

    namespace radio
    {
        static const double kCentralFrequency = 433 * 10e6;
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