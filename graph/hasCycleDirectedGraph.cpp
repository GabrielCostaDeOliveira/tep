
#include <functional>
#include <vector>


template<typename T>
bool hasCycleDirectedGraph(const std::vector<std::vector<T>> &adj){

  std::vector<int> color(adj.size(), 0);

  std::function<bool(T)> dfs = [&](T u){

    color[u] = 1;

    for ( auto v : adj[u]){
      
      if ( color[v] == 0 ){
        if ( dfs(v) )
          return true;

      }else if ( color[v] == 1)
        return true;
    }

    color[u] = 2;
    return false;
  };


  for (T i = 0; i < (T) adj.size() ; i++)
    if ( color[i] == 0 and dfs(i) )
      return true;


  return false;

}
