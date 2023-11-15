#include <gtest/gtest.h>

#include <full_encode_number.h>
#include <full_decode_number.h>
#include <diff_encryption.h>
#include <diff_decryption.h>
#include <binary_file_manager.h>
#include <file_reader.h>
#include <parse_frame.h>

TEST(ExampleTest, example)
{
    ASSERT_TRUE(1 == 1);
}

TEST(CheckClasses, WordToBinary)
{
    double number = 12.5;

    EncodeWord encodeWord(std::make_unique<DiffEncryption>());
    auto seq = BinaryWord(number).getResultBitset();

    auto result = {"00100000000101", "01001000000001", "00000000000001", "00000000000001"};
    size_t k = 0;
    for (auto elem : seq)
    {
        ASSERT_EQ(elem.to_string(), *(result.begin() + k++));
    }
}

TEST(CheckClasses, EncodeBinary)
{
    double number = 12.5;

    EncodeWord encodeWord(std::make_unique<DiffEncryption>());
    auto seq = BinaryWord(number).getResultBitset();

    encodeWord.codeSequence(seq);

    auto result = {"00110000000111", "01101100000001", "00000000000001", "00000000000001"};
    size_t k = 0;
    for (auto elem : seq)
    {
        ASSERT_EQ(elem.to_string(), *(result.begin() + k++));
    }
}

TEST(CheckClasses, DiffDecryption)
{
    double number = 12.5;

    EncodeWord encodeWord(std::make_unique<DiffEncryption>());
    auto seq = BinaryWord(number).getResultBitset();

    encodeWord.codeSequence(seq);

    EncodeWord ahah(std::make_unique<DiffDecryption>());
    ahah.codeSequence(seq);

    auto result = {"00100000000101", "01001000000001", "00000000000001", "00000000000001"};
    size_t k = 0;
    for (auto elem : seq)
    {
        ASSERT_EQ(elem.to_string(), *(result.begin() + k++));
    }
}

TEST(CheckClasses, BinaryToDouble)
{
    double number = 12.5;
    auto seq = BinaryWord(number).getResultBitset();

    BitsetToDouble zxc(seq);

    EXPECT_NEAR(zxc.getDouble(), 12.5, 1e-6);
}

TEST(CheckAll, checkAll)
{
    double number = 12.5;

    EncodeData data(number);
    auto z = data.execute();

    DecodeData decode(z);

    EXPECT_NEAR(number, decode.execute(), 1e-6);
}

TEST(CheckWorkWithFiles, FileReadAndWrite)
{
    std::string file_name("/home/vladimir/pre-detector-signal/library/encode_data/tests/test_files/test.txt");

    BinaryFileManager manager(file_name);
    manager.setStartFrameMarker(1, 0.5);

    for (size_t i = 0; i < 10; ++i)
    {
        manager.addSynchronize();
        auto bitset = EncodeData(12 + static_cast<double>(i) * 0.5).execute();
        manager.writeBitset(bitset);
    }

    manager.~BinaryFileManager();

    FileReader file(file_name);

    auto is_file_read = file.readFrame();
    ASSERT_TRUE(is_file_read);

    auto info = "11111100000000000000000000000000000000000001100100000000110000000000000100000000000001000000000000011"
                "11100010011010001100000001111110000000000100000000000001000000000000011111000100110100011000000011101"
                "10110000000100000000000001000000000000011111000100110100011000000011101111000000001000000000000010000"
                "00000000011111000100110100011000000011111110100000001000000000000010000000000000111110001001101000110"
                "00000011101010000000001000000000000010000000000000111110001001101000110000000111110111000000010000000"
                "00000010000000000000111110001001101000110000000111110010000000010000000000000100000000000001111100010"
                "01101000110000000111010001000000010000000000000100000000000001111100010011010101100000001010000000000"
                "0001000000000000010000000000000111110001001101010110000000101100001100000010000000000000100000000000001";
    ASSERT_EQ(info, file.getCurrentFrameInfo());
}

TEST(CheckWorkWithFiles, ParseData)
{
    std::string frame = "111111000000000000000000000000000000000000011001000000001100000000000001000000000000010000000000000111110001001101000110000000111111000000000010000000000000100000000000001111100010011010001100000001110110110000000100000000000001000000000000011111000100110100011000000011101111000000001000000000000010000000000000111110001001101000110000000111111101000000010000000000000100000000000001111100010011010001100000001110101000000000100000000000001000000000000011111000100110100011000000011111011100000001000000000000010000000000000111110001001101000110000000111110010000000010000000000000100000000000001111100010011010001100000001110100010000000100000000000001000000000000011111000100110101011000000010100000000000001000000000000010000000000000111110001001101010110000000101100001100000010000000000000100000000000001";

    ParseFrame zxc(0.5);

    auto is_ok_frame = zxc.tryToParseFrame(frame);
    ASSERT_TRUE(is_ok_frame);

    auto params = zxc.getParams();


    std::cout << zxc.getNumberFrame() << "\t" << zxc.getTime() << "\n";
    for (size_t i = 0; i < 10; ++i)
    {
        std::cout << params[i] << "\t";
        ASSERT_EQ(params[i], 12 + 0.5 * i);
    }
}

//! 010editor
//! TODO add tests with parse frame and file reader