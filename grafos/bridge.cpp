#include <algorithm>
#include <bits/stdc++.h>
#include <climits>

using namespace std;


void dfs_bridge(int v, int p, vector<pair<int, int>> &bridge,  const vector<vector<int>> &adj, vector<bool> &visited, vector<int> &tin, vector<int> &low,  int& timer){

  visited[v] = true;

  tin[v] = low[v] = timer++;

  for (int to : adj[v]){
    if (to == p)
      continue;

    if (visited[to])
      low[v] = min(low[v], low[to]);
    else {
      dfs_bridge(to, v, bridge,adj, visited, tin, low, timer);

      low[v] = min(low[v], low[to]);

      if ( low[to] > tin[v])
        bridge.push_back({to, v});
      
    }

  }


}


vector<pair<int, int>> find_bridge(const vector<vector<int>> &adj){


  vector<bool> visited(adj.size(), false);
  vector<int> tin(adj.size(), 0), low(adj.size(), 0);
  int timer = 0;

  vector<pair<int, int>> bridge;

  dfs_bridge(0, -1, bridge, adj, visited, tin, low, timer);
  
  return bridge;

}

