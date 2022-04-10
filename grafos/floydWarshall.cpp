#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9;
vector<vector<pair<int, int>>> adj{
	{},
	{ {}, {2, 9}, {3, 7}, {4, 4}, {5, 2}}, 
	{	{}, {1, 9}, {3, 1}, {6, 3}}, 
	{ {}, {1, 7}, {2, 1}, {4, 2} }, 
	{ {}, {1, 4}, {3, 2}, {5, 1} },
	{ {}, {1, 2}, {4, 1}, {6, 11}}, 
	{ {}, {2, 3}, {5, 11} }

};

vector<vector<int>> floyd_warshall(int N){

	vector<vector<int>> dist(N+1, vector<int>(N+1, oo));

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

int main(){

	auto dist = floyd_warshall(6);

	for (int u = 1; u <= 6; u++)
		for ( int v = 1; v <= 6; v++ )
			cout << dist[u][v] << (v == 6 ? "\n" : " ");

}
