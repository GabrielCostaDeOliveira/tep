#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> adj (6+1);

vector<int> dijkstra(int s, int n){
	const int oo {1000000010};

	vector<int> dist(n+1,oo);
	dist[1] =0;

	set<pair<int, int>> U;
	U.emplace(0,s);

	while (not U.empty()){
		auto [d, u] = *U.begin();
		U.erase(U.begin());

		//operação de relaxamanto 
		
		for (auto [v, w] : adj[u])
			if (dist[v]> d + w){

				if(U.count(make_pair(dist[v],v)))
					U.erase(make_pair(dist[v],v));

				dist[v] = d + w;
				U.emplace(dist[v],v);
			}

	}

	return dist;
}

int main(){
	//leitua da lista de ajd

	int u, v, w;

	do{
		cin >> u >> v >> w;

		adj[u].emplace_back(v, w);
	}while(u);


	vector<int> dist = dijkstra(1,6);

	dist.erase(dist.begin());
	for (auto num: dist)
		cout << num << " ";
	cout << endl;
}
