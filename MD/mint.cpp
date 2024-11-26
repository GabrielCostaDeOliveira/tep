
#include<bits/stdc++.h>
#include <iostream>
#include <stdexcept>

template<int MOD>
struct modint {

  long long value;

  modint(long long value = 0) : value(value % MOD) {
    if (value < 0) value += MOD;
  }

  modint operator + (modint const& b) const {
    return modint(value + b.value);
  }

  modint operator - (modint const& b) const {
    return modint(value - b.value);
  }

  modint operator * (modint const& b) const {
    return modint(value * b.value);
  }

  modint& operator += (modint const& b) {
    *this = *this + b;
    return *this;
  }

  modint& operator -= (modint const& b) {
    *this = *this - b;
    return *this;
  }

  modint& operator *= (modint const& b) {
    *this = *this * b;
    return *this;
  }

  bool operator == (modint const& b) const {
    return value == b.value;
  }

  bool operator != (modint const& b) const {
    return value != b.value;
  }

  friend std::ostream& operator<<(std::ostream& os, modint const& a) {
      return os << a.value;
  }

  friend std::istream& operator>>(std::istream& is, modint& a) {
    long long input;
    is >> input;
    a = modint(input); 
    return is;
  }

  modint exp(long long b) const {
    auto fast_pow = [](auto&& self, long long a, long long b) -> long long {
        if (b == 0)
            return 1;
        long long x = self(self, a, b / 2);
        x = (x * x) % MOD;
        return b & 1 ? (a * x) % MOD : x;
    };
    return modint(fast_pow(fast_pow, value, b));
  }

  modint inv() const {
    if (value == 0) {
        throw std::invalid_argument("Inverse of zero is not defined");
    }
    return exp(MOD - 2);  // Only valid if MOD is prime
  }
};



const long long MOD = 1'000'000'007;


using mint = modint<MOD>;

