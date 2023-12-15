#include <functional>
#include <gtest/gtest.h>

#include "../../data-structures/SegTree.cpp"

TEST(SegTree, QUERY_UPDATE){
  SegTree<int> segtree(10, 0, std::plus<int>());

  for ( int i= 0 ;i < 10; i++)
  segtree.update(i, i + 1);


  ASSERT_EQ(segtree.query(0, 9), (1 + 10) * 5);

  segtree.update(9, 0);
  ASSERT_EQ(segtree.query(0, 9), (1 + 10) * 5 - 10);

}


