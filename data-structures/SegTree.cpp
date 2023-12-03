
#include <bits/stdc++.h>


template<typename T>
class SegTree {

  T e;

  std::function<T(T a, T b)> op;

  std::vector<T> ps;

  size_t p;

public:
  
  SegTree(size_t n, T e, std::function<T(T a, T b)> op): e(e), op(op), ps(4*n, e){

    p = 1;
    while (p < n)
      p <<= 1;

  }


  void update(size_t i, T value) {

    i += p;

    ps[i] = value;

    i>>=1;

    while (i){
      ps[i] = op(ps[i*2], ps[i*2 + 1]);
      i >>= 1;

    }

  }


  T query(size_t l, size_t r) {

    l+= p;
    r+= p;

    T la = e, ra = e;

    while (l <= r) {

      if ( l & 1) la = op(ps[l++], la);
      if (~r & 1) ra = op(ra, ps[r--]);

      l>>=1;
      r>>=1;
    }


    return op(la, ra);

  }



};

