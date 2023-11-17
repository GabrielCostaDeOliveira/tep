#include <bits/stdc++.h>
#include <queue>

using namespace std;

vector<int> dijkstra(int s, const vector<vector<pair<int, int>>> &adj){

  const long long oo = 1e9;
  vector<bool> visited(adj.size(), false);
  vector<int> dist(adj.size(), oo);
  dist[s] = 0;

  priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
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

