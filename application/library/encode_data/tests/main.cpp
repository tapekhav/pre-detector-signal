#include <gtest/gtest.h>


int main(int argc, char** argv)
{
    setenv("GTEST_SKIP_MEDIATOR", "ON", 1);
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
