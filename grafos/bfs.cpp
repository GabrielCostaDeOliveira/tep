#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(const vector<vector<int>> &adj,int s){

  const int oo = (int) 1e9;

  vector<int> dist(adj.size(), oo);
  dist[s] = 0;


  queue<int> q;
  q.push(s);


  while (not q.empty()){

    auto u = q.front();
    q.pop();

    for ( auto v : adj[u])
      if (dist[v] == oo){
        q.push(v);
        dist[v] = dist[u] + 1;
      }

  }


  return dist;

}
 
