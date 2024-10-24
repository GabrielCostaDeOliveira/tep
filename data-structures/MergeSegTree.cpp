#include <bits/stdc++.h>

#define all(__v) __v.begin(), __v.end()

template<typename T, T oo>
struct MergeSegTree {



  std::vector<std::multiset<T>> t;

  std::vector<T> v;

  const int n;

  MergeSegTree(const std::vector<T> &V) : t(4*V.size()), n(V.size()), v(V) {

    auto _build = [&](auto&& self, int tl, int tr, int p) -> void {

      if ( tl == tr )

        t[p].insert(v[tl]);

      else {

        int mid = std::midpoint(tl, tr);

        self(self, tl     , mid, 2*p);
        self(self, mid + 1, tr , 2*p + 1);

        t[p].insert(all(t[2*p]));
        t[p].insert(all(t[2*p + 1]));

      }

    };


    _build(_build, 0, n-1, 1);

  }

  void update(int i, T value) {


    T new_value = value;
    T old_value = v[i];
    v[i] = new_value;

    auto _update = [&](auto&& self, int tl, int tr, int p) -> void{


      t[p].insert(new_value);
      t[p].erase(t[p].find(old_value));

      if ( tl != tr ){

        int mid = std::midpoint(tl, tr);

        if ( i <= mid)
          self(self, tl     , mid, 2*p);
        else
          self(self, mid + 1, tr , 2*p + 1);

      }

    };


    _update(_update, 0, n-1, 1);


  }


  T upper_bound (int l, int r, T value) {

    auto _upper_bound = [&](auto&& self, int l, int r, int tl, int tr, int p) -> T {

      if ( l > r)
        return oo;

      if (l == tl and r == tr) {
        auto it = t[p].upper_bound(value);
        return it == t[p].end() ? oo : *it;

      } else {

        int mid = std::midpoint(tl, tr);


        T a = self(self,       l             , std::min(r, mid),   tl   , mid, 2 * p);
        T b = self(self, std::max(mid + 1, l), r               , mid + 1, tr , 2 * p + 1);

        return std::min(a, b);

      }

    };

    return _upper_bound(_upper_bound, l, r, 0, n-1, 1);

  }

};
 
