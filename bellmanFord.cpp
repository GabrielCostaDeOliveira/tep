#include <bits/stdc++.h>

using namespace std;

using edge = tuple<int, int, int>;

vector<int> bellmanfor(int s/*start*/, int N /*n de vertice*/, const vector<edge> & edges /*lista de arestas*/ ){
	const int oo {1000000010};

	vector<int> dist(N + 1, oo);
	dist[s] = 0;

	for (int i = 1; i <= N -1; i++)
		for (auto [u, v, w] : edges)
			if (dist[u] < oo and dist[v] > dist[u] + w )
				dist[v] = dist[u] +w; // relaxamanro 

	return dist;
}


int main(){
	int u, v, w;

	vector<tuple<int, int, int>> edges {{0, 0, 0}};

	//leitua da lista de arestas
	 do{
		cin >> u >> v >> w;
		edges.emplace_back(u,v,w);
	}while ( u != 0 or v != 0 or w != 0 );
	 

	//removendo o primeiro elemento que é um lixo e imprimeindo 
	//as distáncias 
  auto dist = bellmanfor(1, 6,edges);
	dist.erase(dist.begin()); 
	for (int d: dist)
	 cout << d  << " ";
	cout << endl;
}

