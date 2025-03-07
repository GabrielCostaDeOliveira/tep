#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct SegTree {

  vector<ll> t;

  ll n;

  SegTree(ll n) : t(4 * n, 0), n(n) {}

  void update(ll l, ll r, ll value) {

    auto _update = [&](auto &&self, ll l, ll r, ll tl, ll tr, ll p) -> void {
      if (l > r)
        return;

      if (l == tl and r == tr)
        t[p] += value;
      else {
        ll tm = (tl + tr) / 2;
        self(self, l, min(tm, r), tl, tm, 2 * p);
        self(self, max(l, tm + 1), r, tm + 1, tr, 2 * p + 1);
      }
    };

    _update(_update, l, r, 1, n, 1);
  }

  ll query(ll i) {

    auto _query = [&](auto &&self, ll i, ll tl, ll tr, ll p) -> ll {

      if (tl == tr)
        return t[p];

      else {

        ll tm = midpoint(tl, tr);

        if (i <= tm)
          return t[p] + self(self, i, tl, tm, 2 * p);
        else
          return t[p] + self(self, i, tm + 1, tr, 2 * p + 1);
      }
    };

    return _query(_query, i, 1, n, 1);
  }
};
