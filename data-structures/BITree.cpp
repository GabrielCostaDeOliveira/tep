#include<bits/stdc++.h>

template <typename T> struct BITree {

  std::vector<T> t;

  BITree(size_t n) : t(n) {}

  T query(int i) {
    T res = T();
    for (; i >= 0; i = (i & (i + 1)) - 1)
      res += t[i];
    return res;
  }

  void apply(int i, T value) {
    for (; i < (int) t.size(); i = i | (i + 1))
      t[i] += value;
  }

  T query(int a, int b){
    return query(b) - query(a-1);

  }

  void update(int i, T value){
    apply(i, -query(i, i) + value);
  }

};

