#include <bits/stdc++.h>

template <typename  T>
std::vector<T> dijkstra(T s, const std::vector<std::vector<std::pair<T, T>>> &adj){
 
  const T oo = std::numeric_limits<T>::max();
 
  std::vector<T> dist(adj.size(), oo);
  dist[s] = 0;
 
  std::set<std::pair<T,T>> st;
  st.emplace(0, s);
 
  std::vector visited(adj.size(), false);
 
  while (not st.empty()) {
 
    int d, u;
    std::tie(d, u) = *st.begin();
    st.erase(st.begin());
 
    if ( visited[u] )
      continue;
 
    visited[u] = true;
 
    for ( auto [w, v] : adj[u])
      if ( dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        st.emplace(dist[v], v);
      }
 
  }
 
  return dist;
}
