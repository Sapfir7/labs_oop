#include <gtest/gtest.h>
#include "../include/execute.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(tobin(1,1)==1);
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(tobin(2,7)==11);
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(tobin(0,0)==0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}