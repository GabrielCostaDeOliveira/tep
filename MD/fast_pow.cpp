
#include <bits/stdc++.h>

template<typename T>
T fast_pow(const T a, const T b, const T MOD) {
    if (b == 0) 
        return (T)1;
    T p = fast_pow(a%MOD, b/2, MOD) % MOD;
    return b & 1 ? (a*((p*p)%MOD))%MOD : (p*p)%MOD;
}
