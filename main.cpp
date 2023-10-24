#include <encode_word.h>
#include <bitset_to_double.h>
#include <full_encode_number.h>
#include <model_generator.h>
#include <config_parser.h>
#include <binary_file_manager.h>

class CLI
{
public:
    explicit CLI(const std::string& path = "/home/vladimir/pre-detector-signal/result.txt") : _manager(path) {}

    void run(double begin, double end, double step)
    {
        setParams(begin, end, step);
        writeAllData();
    }

private:
    void setParams(double begin, double end, double step)
    {
        _time_interval = Interval(begin, end, step);
    }

    void writeAllData()
    {
        _parser.setData();
        Model model = _parser.getModel();

        ModelGenerator generator(model);
        std::vector<Model> data = generator.generateModel(_time_interval);


        Coordinates coordinates = model.wgs().coordinates();
        auto model_list = { model.temperature(), model.wind_speed().x(), model.wind_speed().y(),
                            coordinates.x(), coordinates.y(), coordinates.z(), model.wgs().speed().z(),
                            model.humidity(), model.board_voltage(), model.control_voltage() };

        auto end = static_cast<size_t>(_time_interval.end / _time_interval.step);
        for (size_t i = 0; i < end; ++i)
        {
            for (size_t j = 0; j < model_list.size(); ++j)
            {
                writeParam(*(model_list.begin() + j));
            }
        }
    }

    void writeParam(double param)
    {
        _encode = std::make_unique<EncodeData>(param);
        _manager.writeBitset(_encode->execute());
        _manager.addSynchronize();
    }

private:
    ConfigParser _parser;
    Interval _time_interval;
    BinaryFileManager _manager;
    std::unique_ptr<EncodeData> _encode;
};


int main() {
    CLI cli;
    cli.run(0, 10, 0.5);


    return 0;
}
