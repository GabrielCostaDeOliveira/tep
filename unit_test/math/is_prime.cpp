#include <gtest/gtest.h>
#include "../../math/is_prime.cpp"




TEST(IS_PRIME, NOT_PRIME ) {

  ASSERT_FALSE(is_prime(1));
  ASSERT_FALSE(is_prime(0));
  ASSERT_FALSE(is_prime(12));
  ASSERT_FALSE(is_prime(1212));
  ASSERT_FALSE(is_prime(10101010));
  ASSERT_FALSE(is_prime(6857*7013));

}

TEST(IS_PRIME, IS_PRIME ) {

  ASSERT_FALSE(is_prime(2));
  ASSERT_FALSE(is_prime(6857));
  ASSERT_FALSE(is_prime(7013));

}

