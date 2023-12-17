#include <functional>
#include <gtest/gtest.h>

#include "../../data-structures/SegTree.cpp"

TEST(SegTree, QUERY_UPDATE_PLUS){
  SegTree<int> segtree(100, 0, std::plus<int>());

  for ( int i= 0 ;i < 100; i++){
    segtree.update(i, i + 1);
    ASSERT_EQ(segtree.query(i, i), i + 1);
  }

  ASSERT_EQ(segtree.query(0, 99), (1 + 100) * 50);

  segtree.update(9, 0);
  ASSERT_EQ(segtree.query(0, 9), (1 + 10) * 5 - 10);

}

TEST ( SegTree, QUERY_UPDATE_MIN){
  
  SegTree<int> segtree(100, (int) 2e9, [](int a, int b){return std::min(a, b);});
  for ( int i= 0 ;i < 100; i++){
    segtree.update(i, i);
    ASSERT_EQ(segtree.query(i, i), i );
  }


  ASSERT_EQ(segtree.query(0, 3), 0);
  ASSERT_EQ(segtree.query(33, 99), 33);

  segtree.update(50, 22);
  ASSERT_EQ(segtree.query(50, 99), 22);

}


TEST(SegTree, QUERY_UPDATE_XOR ){

  using ll = long long;

  SegTree<ll> st(8, 0, std::bit_xor<ll>());

  int i = 0;
  for ( auto v : {3, 2, 4, 5, 1, 1, 5, 3})
    st.update(i++, v);


  ASSERT_EQ(st.query(1, 3), 3);
  ASSERT_EQ(st.query(4, 5), 0);
  ASSERT_EQ(st.query(0, 7), 6);
  ASSERT_EQ(st.query(2, 2), 4);

}

