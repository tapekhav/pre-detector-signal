#ifndef PRE_DETECTOR_SIGNAL_MODEL_GENERATOR_H
#define PRE_DETECTOR_SIGNAL_MODEL_GENERATOR_H

#include <model.pb.h>

#include <utility>

struct Interval
{
    inline explicit Interval(double begin = 0, double end = 10, double step = 0.01)
                                           : begin(begin), end(end), step(step) { assert(step >= 0.01 && step <= 0.5); }

    double begin;
    double end;
    double step;
};

/*!
 * \class ModelGenerator
 * \brief Generate model in time interval
 **/
class ModelGenerator
{
public:
    //! Constructor
    explicit ModelGenerator(Model model) : _model(std::move(model)) {}
    //! Generate signals of model in time interval
    std::vector<double> generateModel(Interval time_interval);
private:
    void setMotion();

    void setAtmosphere();
private:
    Model _model;

    std::function<Coordinates(double)> _motion_formula;
    std::function<void(double)> _wind_formula;
    std::function<void(double)> _atmosphere_formula;
};


#endif //PRE_DETECTOR_SIGNAL_MODEL_GENERATOR_H
