#include <gtest/gtest.h>

#include "../../data-structures/MergeSegTree.cpp"


TEST(MergeSegTree, QUERY_UPDATE){

  std::vector<int> v {5, 6, 6, 10, 1, 2, 3, 4, 4};

  const int oo = 2e9;

  MergeSegTree<int,oo> mst(v);

  ASSERT_EQ(mst.upper_bound(0, v.size() -1, 4), 5);

  ASSERT_EQ(mst.upper_bound(0, 2, 4), 5);

  ASSERT_EQ(mst.upper_bound(3, 6, 4), 10);


  mst.update(0, 10);

  ASSERT_EQ(mst.upper_bound(0, 2, 4), 6);
  
}

