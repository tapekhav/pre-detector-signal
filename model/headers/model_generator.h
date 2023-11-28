#ifndef PRE_DETECTOR_SIGNAL_MODEL_GENERATOR_H
#define PRE_DETECTOR_SIGNAL_MODEL_GENERATOR_H

#include <utility>
#include <functional>

#include <plotter.h>
#include <consts.h>
#include <base_component.h>
#include <model.pb.h>

/*!
 * \class ModelGenerator
 * \brief Generate model in time interval
 **/
class ModelGenerator final : public BaseComponent
{
public:
    //! Constructor
    explicit ModelGenerator(Model init_model);

    //! Generate signals of model in time interval
    void generateModel(const Interval& time_interval);

    [[nodiscard]] inline const Interval& getTimeInterval() const { return _time_interval; }

    [[nodiscard]] inline const std::vector<Model>& getModels() const { return _result_models; }

    [[nodiscard]] inline const Model& operator[](size_t i) const { return _result_models[i]; }
private:
    inline void setTimeInterval(const Interval& time_interval) { _time_interval = time_interval; }

    void setMotionFormula();

    void setTemperatureFormula();

    void setHumidityFormula();

    void setBoardVoltage();

    double getRadius(double lat_rad);
private:
    Model _initial_model;
    Interval _time_interval;
    std::vector<Model> _result_models;

    std::unique_ptr<Plotter> _plotter;
    std::unique_ptr<Plotter> _meters_plotter;

    std::function<Params*(double, const Coordinates&)> _motion_formula;
    std::function<double(double)> _atmosphere_formula;
    std::function<double(double)> _humidity_formula;
    std::function<double(double)> _friis_formula;

    std::function<double(const Coordinates&)> _distance_formula;
};


#endif //PRE_DETECTOR_SIGNAL_MODEL_GENERATOR_H
