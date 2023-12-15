#include <gtest/gtest.h>
#include"../../data-structures/ufds.cpp"

TEST(UFDS, CONSTRUCTOR){

  UFDS<size_t> ufds(10);

  ASSERT_TRUE(ufds.ps.size() == 10);

  for (int i = 0;i <10 ;i++)
    ASSERT_EQ(ufds.ps[i], i);


}

TEST(UFDS, UNION_FIND){

  UFDS<size_t> ufds(10);

  ufds.union_set(1, 2);

  ASSERT_EQ(ufds.find_set(1), ufds.find_set(2));

  ufds.union_set(0, 1);

  ASSERT_EQ(ufds.find_set(0), ufds.find_set(2));


  std::set<size_t> s;

  for (auto e : ufds.ps)
    s.insert(e);

  ASSERT_EQ(s.size(), 8);


}
