#include <gtest/gtest.h>
#include "../../MD/mint.cpp"


TEST(MIT, INV){

  for ( auto e  : {123, 201'001'000, -201'001'000, -5,  1, -1 }){
    ASSERT_EQ(mint(e) * mint(e).inv(), mint(1));
  }

}

