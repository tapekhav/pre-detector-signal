#ifndef PRE_DETECTOR_SIGNAL_CONSTS_H
#define PRE_DETECTOR_SIGNAL_CONSTS_H

#include <cstdint>

namespace consts
{
    namespace marker
    {
        static const uint8_t startFrameMarker[] = {0xFC, 0x00};
    }

    namespace physics
    {
        static const double g = 9.81;

        static const double L = 0.0065;
        static const double H = 1500;

        static const double TCV = 0.0002;
        static const double TC_t = 0.0001;

        static const double k_major_axis = 6378137.0;
        static const double k_minor_axis = 6356752.3142;
    }
}

#endif //PRE_DETECTOR_SIGNAL_CONSTS_H
