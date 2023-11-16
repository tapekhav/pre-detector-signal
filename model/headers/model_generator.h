#ifndef PRE_DETECTOR_SIGNAL_MODEL_GENERATOR_H
#define PRE_DETECTOR_SIGNAL_MODEL_GENERATOR_H

#include <model.pb.h>
#include <plotter.h>
#include <consts.h>

#include <utility>

/*!
 * \class ModelGenerator
 * \brief Generate model in time interval
 **/
class ModelGenerator
{
public:
    //! Constructor
    explicit ModelGenerator(Model model);

    //! Generate signals of model in time interval
    std::vector<Model> generateModel(Interval time_interval);
private:
    void setMotionFormula();

    void setTemperatureFormula();

    void setHumidityFormula();

    void setBoardVoltage();

    double getRadius(double lat_rad);
private:
    Model _initial_model;
    std::unique_ptr<Plotter> _plotter;
    std::unique_ptr<Plotter> _meters_plotter;

    std::function<Params*(double, const Coordinates&)> _motion_formula;
    std::function<double(double)> _atmosphere_formula;
    std::function<double(double)> _humidity_formula;
    std::function<double(double)> _friis_formula;

    std::function<double(const Coordinates&)> _distance_formula;
};


#endif //PRE_DETECTOR_SIGNAL_MODEL_GENERATOR_H
