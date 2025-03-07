#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T>
struct SegTree {

  ll n;
  vector<T> t;

  SegTree(size_t n_p) : n(n_p),  t(4 * n_p, 0) {}

  void update(size_t l, size_t r, const T value) {

    auto _update = [this, &value](auto &&self, size_t l, size_t r, size_t tl, size_t tr, size_t p) -> void {
      if (l > r)
        return;

      if (l == tl and r == tr) {
        t[p] += value;
        return;
      }

      size_t tm = midpoint(tl, tr);

      self(self, l, min(tm, r), tl, tm, 2 * p);
      self(self, max(l, tm + 1), r, tm + 1, tr, 2 * p + 1);
    };

    _update(_update, l, r, 0, n-1, 1);
  }

  T query(const size_t i) {

    auto _query = [this, i](auto &&self, size_t tl, size_t tr, T p) -> ll {
      if (tl == tr)
        return t[p];

      size_t tm = midpoint(tl, tr);

      if (i <= tm)
        return t[p] + self(self, tl, tm, 2 * p);
      else
        return t[p] + self(self, tm + 1, tr, 2 * p + 1);
    };

    return _query(_query, 0, n-1, 1);
  }
};

