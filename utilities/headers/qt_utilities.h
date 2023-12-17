#ifndef PRE_DETECTOR_SIGNAL_QT_UTILITIES_H
#define PRE_DETECTOR_SIGNAL_QT_UTILITIES_H

#include <vector>
#include <qvector.h>

namespace qt
{
    template<class T>
    QVector<T> toQVector(std::vector<T>&& vec)
    {
        QVector<T> result;
        for (const auto& element : vec)
        {
            result.append(element);
        }

        return result;
    }
    
};

#endif //! PRE_DETECTOR_SIGNAL_QT_UTILITIES_H
