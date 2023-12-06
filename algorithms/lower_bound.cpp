#include <bits/stdc++.h>

template<typename T>
T lower_bound(std::function<T(T x)> f /*The function F must be non-decreasing.*/, T value, T l, T r){

  while (l < r) {

    T mid = std::midpoint(l, r);

    if ( f(mid) < value)
      l = mid + 1;
    else 
      r = mid;

  }

  return l;
}
