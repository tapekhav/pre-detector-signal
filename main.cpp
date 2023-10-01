#include <iostream>
#include <config_parser.h>

int main()
{
    ConfigParser a;
    a.setData();
    auto mod = a.getModel();

    std::cout << mod.wind_speed() << "\n";

    return 0;
}
