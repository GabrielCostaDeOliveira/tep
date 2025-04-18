#include <gtest/gtest.h>

#include "../../graph/hasCycleDirectedGraph.cpp"


TEST(CYCLE_DIRECTED_GRAPH, WEAKLY_CONNECTED_GRAPH){

  std::vector<std::vector<int>> adj(8);

  adj[0].push_back(1);
  adj[1].push_back(2);
  adj[2].push_back(3);
  adj[4].push_back(5);
  adj[5].push_back(2);

  ASSERT_FALSE(hasCycleDirectedGraph(adj));
}



TEST(CYCLE_DIRECTED_GRAPH, NO_EDGE){

  std::vector<std::vector<int>> adj(100);

  ASSERT_FALSE(hasCycleDirectedGraph(adj));
  
}

TEST(CYCLE_DIRECTED_GRAPH, EMPTY){

  std::vector<std::vector<int>> adj;

  ASSERT_FALSE(hasCycleDirectedGraph(adj));
  
}

TEST(CYCLE_DIRECTED_GRAPH, TRUE){

  std::vector<std::vector<int>> adj(8);

  adj[0].push_back(1);
  adj[1].push_back(2);
  adj[2].push_back(3);
  adj[4].push_back(5);
  adj[5].push_back(2);
  adj[3].push_back(4);


  ASSERT_TRUE(hasCycleDirectedGraph(adj));
}

