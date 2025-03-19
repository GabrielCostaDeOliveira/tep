#include <gtest/gtest.h>
#include "../../math/mint.cpp"


TEST(MIT, INV){

  for ( auto e  : {123, 201'001'000, -201'001'000, -5,  1, -1 }){
    ASSERT_EQ(mint(e) * mint(e).inv(), mint(1));
  }

}

TEST(MIT, CONSTRUCTOR ) {
  mint a = MOD + 1;
  ASSERT_EQ(a, mint(1));

  mint b = MOD + 1235;

  ASSERT_EQ(b, mint(MOD + 1235));

}


TEST(MIT, MINUS){

   mint a = 428767833 - 768543831;
   ASSERT_EQ(a.value, ((428767833 - 768543831) % MOD + MOD) );

}

