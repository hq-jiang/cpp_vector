#include "vector.h"

#include <gtest/gtest.h>

TEST(SimpleTest, test) {
  ASSERT_EQ(6, 6);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}