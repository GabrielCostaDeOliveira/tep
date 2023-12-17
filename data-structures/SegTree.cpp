
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


  T query(size_t a, size_t b) {

    a+= p;
    b+= p;

    T la = e, ra = e;

    while (a <= b) {

      if ( a & 1) la = op(ps[a++], la);
      if (~b & 1) ra = op(ra, ps[b--]);

      a>>=1;
      b>>=1;
    }


    return op(la, ra);

  }



};

