
#include <bits/stdc++.h>


template<typename T>
T fast_pow(const T a, const T b, const T MOD) {

  if (b == 0)
    return 1;

  long long x = fast_pow( (T) a, (T) b / 2ll);

  x = (x * x) % MOD;

  return b & 1 ? (a * x) % MOD : x;
}
