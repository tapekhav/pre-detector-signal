#include <encode_word.h>
#include <bitset_to_double.h>
#include <full_encode_number.h>
#include <model_generator.h>
#include <config_parser.h>
#include <binary_file_manager.h>

class CLI
{
public:
    explicit CLI(const std::string& path = "/home/vladimir/pre-detector-signal/result.sh") : _manager(path) {}

    void encodeData(double begin, double end, double step)
    {
        setParams(begin, end, step);
        writeAllData();
    }

    std::vector<double> decodeData()
    {

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
            _manager.setStartFrameMarker(i, 0.5);
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

uint8_t countOne(uint32_t num)
{
    std::bitset<14> bitset(num);

    uint8_t k = 0;
    for(size_t i = 0; i < bitset.size(); ++i)
    {
        k = bitset[i] ? k + 1 : k;
    }

    return k;
}


int main() {
    unsigned int informationSequence = 123;

    int numBits = 12;

    std::vector<uint32_t> vec;
    int numGroups = (numBits + 11) / 12;

    informationSequence = informationSequence & 0xFFFFFFFE;
    for (int i = numGroups - 1; i >= 0; i--)
    {
        unsigned int group = (informationSequence >> (12 * i)) & 0xFFF;
        vec.push_back(group);
    }

    std::fstream file;
    file.open("/home/vladimir/pre-detector-signal/result.sh");
    for (auto group : vec)
    {
        group = (group << 1);
        group = countOne(group) % 2 == 1 ? group + 8192 : group;
        group += 1;
        file.write(reinterpret_cast<char*>(&group), sizeof(group));
    }

    file.close();

    // Создаем бинарный файл для записи
    /*std::ofstream file("output.bin", std::ios::binary);

    // Маркер начала кадра (11111100000 в двоичном представлении)
    uint16_t frameMarker = 0b11111100000;

    // Номер текущего кадра
    uint16_t frameNumber = 42; // Здесь нужно установить реальный номер кадра

    // Время текущего кадра (в секундах, можно установить другое значение)
    double frameTime = 0.123;

    // Преобразуем время в шестнадцатеричное 14-разрядное слово (значение в миллисекундах)
    uint16_t frameTimeHex = static_cast<uint16_t>(frameTime * 1000);

    // Создаем байт с признаком четности (0-й бит)
    uint16_t parityBit = 0; // Ваш расчет четности здесь

    // Создаем 14-разрядное слово с номером кадра и временем
    uint16_t frameData = (frameNumber << 1) | (parityBit << 0);
    frameData |= (frameTimeHex << 1);

    // Записываем маркер начала кадра
    file.write(reinterpret_cast<char*>(&frameMarker), sizeof(frameMarker));

    // Записываем данные кадра
    file.write(reinterpret_cast<char*>(&frameData), sizeof(frameData));

    // Закрываем файл
    file.close();*/

    return 0;
}
