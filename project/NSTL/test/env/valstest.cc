#include "gtest/gtest.h"


#include "nstl_vals.h"

int in=2;

IN_SPACE
int in=1;
OUT_SPACE

TEST(VALS,SPACE) {
  EXPECT_EQ(in,2);
  EXPECT_EQ(NSTLSPACE::in,1);
}
