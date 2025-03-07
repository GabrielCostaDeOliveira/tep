#include <bits/stdc++.h>
 
using ll = long long;
 
using namespace std;
 
struct SegTree {
 
  vector<ll> t;
 
  ll n;
 
  SegTree(ll n) : t(4*n), n(n){ }
 
 
  void update(ll i, ll value){
 
    i++;
 
    auto _update = [&](auto&&self, ll tl, ll tr, ll p)-> void{
 
      if ( tr == tl)
        t[p] = value;
      else {
        ll tm = midpoint(tl, tr);
 
        if ( i <= tm)
          self(self, tl, tm, 2*p);
        else
          self(self, tm+1, tr, 2*p + 1);
 
        t[p] = t[2*p] + t[2*p + 1];
 
      }
 
    };
 
 
    _update(_update, 1, n, 1);
 
  }
 
 
  ll query(ll l, ll r){
 
    l++, r++;
 
    auto _query = [&](auto&&self, ll l, ll r, ll tl, ll tr, ll p)->ll{
 
      if ( l > r)
        return 0;
 
      if ( tl == l and tr == r)
        return t[p];
      else {
 
        ll tm = midpoint(tl, tr);
 
        ll a = self(self, l, min(tm, r), tl, tm, 2*p);
        ll b = self(self, max(l, tm+1), r, tm+1, tr, 2*p + 1);
 
        return a + b;
 
      }
 
    };
 
 
   return _query(_query, l, r, 1, n, 1);
 
  }
 
};
 
