#include <bits/stdc++.h>

template<typename T>
T fast_pow(const T a, const T b, const T MOD) {

  if (b == 0)
    return 1;

  long long x = fast_pow( (T) a, (T) b / 2ll);

  x = (x * x) % MOD;

  return b & 1 ? (a * x) % MOD : x;
}

template<typename T>
T fast_pow2(const T a,const T b, const T MOD) {

  T res = 1;

  for (; b; b>>=1, a = (a*a)%MOD)
    if (b&1)
      res = (res * a)%MOD;

  return res;
}
