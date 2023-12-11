#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9;

std::vector<std::vector<int>> floyd_warshall(int N, std::vector<std::vector<pair<int, int>>> adj){

  std::vector<vector<int>> dist(N+1, std::vector<int>(N+1, oo));

	for ( int u = 1; u <= N; u++ )
		dist[u][u] = 0;

	for ( int u = 1; u <= N; u++ )
		for ( auto [v, w] : adj[u] )
			dist[u][v] = w;

	for ( int k = 1; k <= N; k++ )
		for ( int u = 1; u <= N; u++ )
			for ( int v = 1; v <= N; v++ )
				if ( dist[u][k] < oo and dist[k][v] < oo )
					dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);


	return dist;
}

