
#include <gtest/gtest.h>
#include "../../MD/fat.cpp"
#include <map>


TEST(FAT, COMPOSITE_NUMBER){

  using ll = long long;
  std::map<ll, ll> m {{5, 2}, {7, 1}, {13, 1}};

  ASSERT_EQ(fat(2275), m);

}

TEST(FAT, PRIME_NUMER){

  using ll = long long;
  std::map<ll, ll> m {{(ll) 1e9 + 7, 1}};

  ASSERT_EQ(fat(1e9 + 7), m);

}

TEST(FAT, PERFECT_SQUARE){

  using ll = long long;
  std::map<ll, ll> m {{13, 2}};

  ASSERT_EQ(fat(169), m);

}



TEST(FAT, BORDER_CASES_ZERO){

  using ll = long long;
  std::map<ll, ll> m;

  
  ASSERT_EQ(m, fat(0));



}

TEST(FAT, BORDER_CASES_ONE){

  using ll = long long;
  std::map<ll, ll> m;
  
  ASSERT_EQ(m, fat(1));
}
