#include <bits/stdc++.h>

struct binary_lifting{

  std::vector<std::vector<int>> far;
  const size_t LOGMAX = 30;


  binary_lifting(std::vector<int> func_graph) : LOGMAX(30) {

    far.assign(LOGMAX, std::vector<int>( func_graph.size(), -1));

    for (size_t i = 0; i < func_graph.size(); i++) 
      far[0][i] =  func_graph[i];

    for (size_t h = 1; h < LOGMAX; h++ ) 
      for (size_t i = 0; i < func_graph.size(); i++) 
        if (far[h-1][i] != -1)
          far[h][i] = far[h-1][far[h-1][i]];

  }


  size_t forwoard(int h, int i) {
     /* find hth ancestor of i */

    for (size_t k = 0; k < LOGMAX; k++ ) 
      if ( (h >> k) & 1 ) {

        i = far[k][i];

        if (i == -1)
          break;
      }

    return i;

  }

};
