#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9;
vector<vector<pair<int, int>>> adj;


vector<vector<int>> floyd_warshall(int n){

	vector<vector<int>> dist(n +1, vector<int>(n+1, oo));

	for (int u = 1; u <= n; ++u)
		dist[u][u] = 0;

	for (int u =1 ; u <= n; ++u)
		for (auto[v, w] : adj[u])
			dist[u][v] = w;

	for (int k = 1; k <= n; ++k)
		for (int u = 1; u <= 1; ++u)
			for (int v = 1; v <=1; ++v)
				if (dist[u][k] < oo and dist[k][v] < oo)
					dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);

	return dist;
}

int main(){

}
