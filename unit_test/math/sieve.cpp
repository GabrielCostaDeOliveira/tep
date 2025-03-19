#include <gtest/gtest.h>
#include "../../math/sieve.cpp"


TEST(sieve, simple_test){

  std::vector<long long> v{2, 3, 5, 7};

  ASSERT_EQ(sieve(10), v);

}

TEST(sieve, count){

  ASSERT_EQ(sieve(100).size(), 25);

  ASSERT_EQ(sieve(1e6).size(), 78498);
}

