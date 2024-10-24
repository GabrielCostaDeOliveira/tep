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

TEST ( SegTree, QUERY_UPDATE_MIN_PAIR){
  const int oo = 1e9;

                  // 0  1  2   3   4   5   6   7  8  9
  std::vector<int> v{9, 2, 1, 12, 23, 23, 23, 15, 9, 1};

  SegTree<std::pair<int, int>> segtree(v.size(), {oo, oo}, [](std::pair<int, int> a, std::pair<int, int> b){return std::min(a, b);});

  for ( size_t i = 0; i < v.size(); i++)
    segtree.update(i, {v[i], i});


  ASSERT_EQ(segtree.query(0, 0), std::make_pair(9 , 0));
  ASSERT_EQ(segtree.query(1, 1), std::make_pair(2 , 1));
  ASSERT_EQ(segtree.query(2, 2), std::make_pair(1 , 2));
  ASSERT_EQ(segtree.query(3, 3), std::make_pair(12, 3));
  ASSERT_EQ(segtree.query(4, 4), std::make_pair(23, 4));

  ASSERT_EQ(segtree.query(3, 4), std::make_pair(12, 3));
  ASSERT_EQ(segtree.query(3, 8), std::make_pair(9, 8));
  ASSERT_EQ(segtree.query(4, 7), std::make_pair(15, 7));


}


TEST(SegTree, QUERY_UPDATE_XOR ){

  using ll = long long;

  SegTree<ll> st(8, 0, std::bit_xor<ll>());

  int i = 0;
  for ( auto v : {3, 2, 4, 5, 1, 1, 5, 3})
    st.update(i++, v);

  ASSERT_EQ(st.query(0, 0), 3);
  ASSERT_EQ(st.query(1, 1), 2);
  ASSERT_EQ(st.query(3, 3), 5);

  ASSERT_EQ(st.query(1, 3), 3);
  ASSERT_EQ(st.query(4, 5), 0);
  ASSERT_EQ(st.query(0, 7), 6);
  ASSERT_EQ(st.query(2, 2), 4);

}
