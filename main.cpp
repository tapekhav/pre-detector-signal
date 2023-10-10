#include <iostream>
#include <config_parser.h>
#include <model_generator.h>
#include <binary_file_manager.h>

int main()
{
    ConfigParser a;
    a.setData();
    auto mod = a.getModel();

    ModelGenerator zxc(mod);
    Interval time(0, 100000, 0.5);
    auto vec = zxc.generateModel(time);

    for (const auto& i : vec) {
        std::cout << i.temperature() << "\n";
        std::cout << i.humidity() << "\n";
        std::cout << i.board_voltage() << "\n";
        std::cout << i.wgs().coordinates().z() << "\n";
        std::cout << i.wgs().coordinates().x() << "\n";
        std::cout << i.wgs().coordinates().y() << "\n\n\n";
    }


    return 0;
}