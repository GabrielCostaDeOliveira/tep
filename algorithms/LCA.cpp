#include <bits/stdc++.h>

struct LCA {

  const int LOGMAX;
  std::vector<std::vector<int>> up;
  std::vector<int> level;

  LCA(std::vector<std::vector<int>> &adj, int root) : LOGMAX(30), up(), level() {

    up.assign(LOGMAX + 1, std::vector<int> (adj.size(), -1));

    level.assign(adj.size(), 0);

    auto dfs = [&](auto &&dfs, int u, int p) -> void {

      if ( p != -1)
        level[u] = level[p] + 1;

      up[0][u] = p;

      for ( int h = 1; h <= LOGMAX; h++)
        if ( up[h-1][u] != -1)
          up[h][u] = up[h-1][up[h-1][u]];

      for ( int v : adj[u])
        if ( v != p)
          dfs(dfs, v, u);

    };


    dfs(dfs, root, -1);

  }

  int lca(int x, int y) {
    
    if (level[x] < level[y])
      std::swap(y, x);

    // level[x] >= level[y]

    for (int h = LOGMAX; h >= 0; h--)
      if ( level[x] - (1 << h)  >= level[y])
        x = up[h][x];

    if ( x == y)
      return x;

    for ( int h = LOGMAX; h >= 0; h-- )
      if ( up[h][x] != up[h][y]){
        x = up[h][x];
        y = up[h][y];
      }

    return up[0][x];

  }


};

