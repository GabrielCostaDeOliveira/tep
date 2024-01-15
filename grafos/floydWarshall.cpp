#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll oo = 9e18;

std::vector<std::vector<ll>>
floyd_warshall(ll n, const std::vector<std::tuple<ll, ll, ll>> &adj) {

  std::vector<vector<ll>> dist(n, std::vector<ll>(n, oo));

  for (ll u = 0; u < n; u++)
    dist[u][u] = 0;

  for (const auto &[a, b, w] : adj) 
    dist[a][b] = min(w, dist[a][b]);

  for (ll k = 0; k < n; k++)
    for (ll u = 0; u < n; u++)
      for (ll v = 0; v < n; v++)
        if (dist[u][k] < oo and dist[k][v] < oo)
          dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);

  return dist;
}
