#include "gtest/gtest.h"


#include "nstl_vals.h"

int in=2;

IN_NSTL
int in=1;
OUT_NSTL

TEST(VALS,SPACE) {
  EXPECT_EQ(in,2);
  EXPECT_EQ(NSTLSPACE::in,1);
}
