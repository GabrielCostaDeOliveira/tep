#include <algorithm>
#include <bits/stdc++.h>
#include <climits>

using namespace std;


void dfs_bridge(int v, int p, vector<pair<int, int>> &bridge,  const vector<vector<int>> &adj, vector<int> &tin, vector<int> &low,  int& timer){

  tin[v] = low[v] = timer++;

  for (int to : adj[v]){

    if (not tin[to]){
      dfs_bridge(to, v, bridge,adj, tin, low, timer);

      low[v] = min(low[v], low[to]);

      if ( low[to] > tin[v])
        bridge.push_back({to, v});

    } else if ( to != p) 

      low[v] = min(low[v], low[to]);

  }


}


vector<pair<int, int>> find_bridge(const vector<vector<int>> &adj){

  vector<int> tin(adj.size(), 0), low(adj.size(), 0);
  int timer = 0;

  vector<pair<int, int>> bridge;

  dfs_bridge(0, -1, bridge, adj, tin, low, timer);
  
  return bridge;

}


