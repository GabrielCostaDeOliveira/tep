#include <bits/stdc++.h>

using namespace std;


std::vector<bool> visited;
vector<vector<int>> adj;

auto dfs = [](auto &&dfs, int u){

  if (visited[u])
    return;

  visited[u] = true;

  for ( auto v : adj[u])
    dfs(dfs, v);

};


