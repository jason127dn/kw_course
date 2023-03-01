#include "gtest/gtest.h"
#include "area.h"

TEST(test_area, test_area)
{
  EXPECT_EQ(AREA(square)(10),100.);
  EXPECT_EQ(area_square(100),10000.);
}

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

