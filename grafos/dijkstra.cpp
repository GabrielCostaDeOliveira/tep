#include <limits>
#include <queue>
#include <vector>

template <typename  T>
std::vector<T> dijkstra(T s, const std::vector<std::vector<std::pair<T, T>>> &adj){

  const T oo = std::numeric_limits<T>::max();
  std::vector<bool> visited(adj.size(), false);
  std::vector<T> dist(adj.size(), oo);
  dist[s] = 0;

  std::priority_queue<std::pair<T,T>, std::vector<std::pair<T, T>>, std::greater<std::pair<T,T>>> pq;
  pq.emplace(0, s);

  while (not pq.empty()){

    auto [d, u] = pq.top();
    pq.pop();

    if (visited[u])
      continue;

    visited[u] = true;

    for (auto [w, v] : adj[u])
      if ( dist[u] + w < dist[v]){
        dist[v] = dist[u] + w;
        pq.emplace(dist[v], v);
      }
  }

  return dist;
}

