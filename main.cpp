/*#include <iostream>
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
} */

/*
#include <iostream>
#include <bitset>

// Функция для кодирования координатных параметров
int encodeCoordinate(int x, int y) {
    // Используем побитовые операции для упаковки значений x и y в 28-и разрядное слово
    int encodedValue = 0;
    encodedValue |= (x & 0x3FFF);   // Нижние 14 бит для x
    encodedValue |= (y & 0x3FFF) << 14;  // Верхние 14 бит для y
    encodedValue |= (1 << 26); // Установка маркера (13-й бит)
    encodedValue |= (1 << 0);  // Установка бита четности (0-й бит)

    return encodedValue;
}

// Функция для декодирования координатных параметров
#include <iostream>
#include <bitset>

// Функция для кодирования координатных параметров в 64-битное число
long long encodeCoordinates(int x, int y) {
    // Используем битовые маски и сдвиги для упаковки значений x и y в 64-битное число
    long long encodedValue = 0;
    encodedValue |= (static_cast<long long>(x) & 0x3FFFFFFF);          // Нижние 30 бит для x
    encodedValue |= (static_cast<long long>(y) & 0x3FFFFFFF) << 30;   // Верхние 30 бит для y
    encodedValue |= (static_cast<long long>(1) << 60); // Установка маркера (13-й бит)
    encodedValue |= (static_cast<long long>(1) << 0);  // Установка бита четности (0-й бит)

    return encodedValue;
}

// Функция для декодирования координатных параметров из 64-битного числа
void decodeCoordinates(long long encodedValue) {
    int x = static_cast<int>(encodedValue & 0x3FFFFFFF);          // Декодирование x (нижние 30 бит)
    int y = static_cast<int>((encodedValue >> 30) & 0x3FFFFFFF);  // Декодирование y (верхние 30 бит)

    bool parityBit = (encodedValue & 1);    // Проверка бита четности (0-й бит)
    bool markerBit = ((encodedValue >> 60) & 1); // Проверка маркера (13-й бит)

    std::cout << "Декодированные координаты: x = " << x << ", y = " << y << std::endl;
    std::cout << "Бит четности: " << parityBit << std::endl;
    std::cout << "Маркерный бит: " << markerBit << std::endl;
}

int main() {
    int x = 100; // Пример координаты x
    int y = 200; // Пример координаты y

    long long encodedValue = encodeCoordinates(x, y);

    std::cout << "Закодированное значение: " << std::bitset<64>(22.132) << std::endl;

    decodeCoordinates(encodedValue);

    return 0;
}
*/
#include <iostream>

#include <word_to_binary.h>
#include <encode_word.h>
#include <diff_encryption.h>
#include <diff_decryption.h>

int main() {
    double number = 12.5;
    EncodeWord encodeWord(std::make_unique<DiffEncryption>());
    auto seq = BinaryWord(number).getResultBitset();

    encodeWord.codeSequence(seq);

    for (auto elem : BinaryWord(number).getResultBitset())
    {
        std::cout << elem << "\n";
    }

    std::cout << "\n\n\n";

    for (auto elem : seq)
    {
        std::cout << elem << "\n";
    }

    std::cout << "\n\n\n";

    EncodeWord ahah(std::make_unique<DiffDecryption>());

    ahah.codeSequence(seq);
    for (auto elem : seq)
    {
        std::cout << elem << "\n";
    }

    //0100000000101001000000000000000000000000000000000000000000000000

    return 0;
}
