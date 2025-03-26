#include <bits/stdc++.h>


template <typename T>
std::vector<T> topological_sort(const std::vector<std::vector<T>> &adj){
  std::vector<T> o;
  std::vector<bool> visited(adj.size(), false);

  std::function<void(T)> dfs = [&](T u){
    visited[u] = true;

    for (T v : adj[u])
      if(not visited[v])
        dfs(v);

    o.push_back(u);
  };


  for (T u = 0; u < adj.size(); u++)
    if (not visited[u])
      dfs(u);


  reverse(o.begin(), o.end());
  return o;

}

