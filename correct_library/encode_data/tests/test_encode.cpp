#include <gtest/gtest.h>
#include <full_encode_number.h>
#include <full_decode_number.h>
#include <diff_encryption.h>
#include <diff_decryption.h>

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
    double number = 15.01234;

    EncodeData data(number);
    auto z = data.execute();
    DecodeData decode(z);

    EXPECT_NEAR(number, decode.execute(), 1e-6);
}

//! 010editor