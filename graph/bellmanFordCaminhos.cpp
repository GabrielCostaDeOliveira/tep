#include <bits/stdc++.h>

using namespace std;

pair<vector<int>,vector<int>> bellmanford(int s/*start*/, int N /*n de vertice*/, const vector< tuple<int, int, int>> & edges /*lista de arestas*/ ){
	const int oo {1000000010};

	vector<int> dist(N + 1, oo), pred(N +1, oo);
	pred[s] = s;
	dist[s] = 0;

	for (int i = 1; i <= N -1; i++)
		for (auto [u, v, w] : edges)
			if (dist[u] < oo and dist[v] > dist[u] + w ){
				dist[v] = dist[u] +w; // relaxamanro
				pred[v] = u;
			}

	return {dist, pred} ;
}

vector<pair<int,int>> path(int s, int u, const vector<int> & pred){
	vector<pair<int, int>> p;
	int v = u;

	do{
		p.emplace_back(pred[v], v);
		v = pred[v];
	}while( v != s );

	reverse(p.begin(), p.end());

	return p;
}

int main(){
	int u, v, w;

	vector<tuple<int,int,int>> edges;

	do{
		cin >> u >> v >> w;
		edges.emplace_back(u, v, w);
	}while(u != 0 and v != 0 and w != 0);
	
	auto [dist, pred] = bellmanford(1,6, edges);

	dist.erase(dist.begin()); 
	for (int u : dist)
		cout << u << " ";
	cout << endl;

	for (int u = 1; u <= 6; u++){
		vector<pair<int, int>> caminho = path(1, u, pred);
		cout << "de 1 para " << u << endl;
		for (auto [i , f] : caminho )
			cout << "(" << i << ", "<< f<< ") ";
		cout << endl;

	}


}



