#include "vector.h"

#include <gtest/gtest.h>

TEST(CppVector, DefaultConstructor) {
  Vector vector;
  ASSERT_EQ(vector.size(), 0);
  ASSERT_EQ(vector.capacity(), 0);
  ASSERT_THROW(vector.get(0), std::invalid_argument);
}

TEST(CppVector, SizedConstructor) {
  Vector vector(4);
  ASSERT_EQ(vector.size(), 4);
  ASSERT_EQ(vector.capacity(), 4);
  for(int i=0; i<vector.size(); ++i) {
    ASSERT_EQ(vector.get(i), 0);
  }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}