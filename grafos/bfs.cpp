#include <bits/stdc++.h>

using namespace std;

const int MAX = 13;

vector<vector<int>> adj {
{},
{2, 3},         //1
{1, 4, 5},      //2
{1, 6},         //3
{2},            //4
{2, 6, 8, 9},   //5
{3, 5,7 , 10},  //6
{6},            //7
{5, 11},        //8
{5, 10},        //9
{6, 9},         //10
{8, 12, 13},    //11
{11},           //12
{11}};          //13

bitset<MAX+1> visited;

void bfs1(int u){
	queue<int> q;
	q.push(u);

	while (not q.empty()){
		int u = q.front(); q.pop();

		cout << u << " ";
		for(int v : adj[u])
			if (not visited[v]){
				visited[v] = true; 
				q.push(v);
			}
	}
}

//com as distancias am arestas

const int oo = 1e9 +10;

vector<int> bfs2(int n){
	vector<int> dist(MAX + 1, oo);

	queue<int> q;

	q.push(n);
	dist[n] = 0;

	while ( not q.empty() ){
		auto u = q.front();
		q.pop();

		//visitamos
		cout << u << " ";
		//

		for (auto v : adj[u])
			if ( dist[v] == oo ){
				dist[v] = dist[u] + 1;
				q.push(v);
			}

	}


	return dist;

}


int main(){
	bfs1(1);
	cout << endl;
	auto dist =bfs2(1);
	cout << endl;



	for (int i = 1; i <= MAX; i++)
		cout << dist[i] << " ";
	cout << endl;
	}
