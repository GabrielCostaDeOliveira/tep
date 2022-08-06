#include <bits/stdc++.h>

using namespace std;

const int oo {1000000010};
const int MAX_V = 6;

using ii = pair<int, int>;

vector<vector<ii>> adj {

{},
{ {2, 9}, {3, 7}, {4, 4}, {5, 2} },  //A
{ {1, 9}, {3, 1}, {6, 3} },          //B
{ {1, 7}, {2, 1}, {4, 2} },          //C
{ {1, 4}, {3, 2}, {5, 1} },          //D
{ {1, 2}, {4, 1}, {6, 11} },         //E
{ {2, 3}, {5, 11} }                  //F
																		 //
};

vector<int> dijkstra1(int s, int n){
	vector<int> dist(n+1, oo);
	dist[s] = 0;

	priority_queue<ii, vector<ii>, greater<ii>> p;
	p.push(ii(s, 0));

	bitset<MAX_V + 1> visited;

	while ( not p.empty() ){

		auto [u, d] = p.top();
		p.pop();

		if ( visited[u] )
			continue;

		visited[u] = true;

		for (auto [v, w] : adj[u])
			if ( dist[v] > w + d ){
				dist[v] = d + w;
				p.emplace(dist[v], v);
			}
	}

	return dist;
}

vector<int> dijkstra2(int s, int n){

	vector<int> dist(n+1,oo);
	dist[1] = 0;

	set<ii> U;
	U.emplace(0,s);

	while (not U.empty()){
		auto [d, u] = *U.begin();
		U.erase(U.begin());

		//operação de relaxamanto 
		
		//para todas as adjacẽncias de u
		for (auto [v, w] : adj[u])
			if (dist[v]> d + w){

				//se já tem um distancia para v apague
				if(U.count(make_pair(dist[v],v)))
					U.erase(make_pair(dist[v],v));

				dist[v] = d + w;
				U.emplace(dist[v],v);
			}
	}

	return dist;
}

int main(){
	for  ( auto d : dijkstra1(1, MAX_V) )
		cout << d << " ";
	cout << endl;

	for  ( auto d : dijkstra2(1, MAX_V) )
		cout << d << " ";
	cout << endl;
		
}
