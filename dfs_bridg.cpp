#include <bits/stdc++.h>

#define MAX 400 

using namespace std;

vector<int> dfs_low (MAX, 0), dfs_num (MAX,0);

vector<vector<int>> adj {
 {},
 {2, 3},
 {1, 3},
 {1, 2, 4},
 {3, 5, 6},
 {4, 6},
 {4, 5}
};


void dfs_bride (int u, int p, int & next, vector<pair<int,int>> & bridges){


	dfs_low[u] = dfs_num[u] = next++;


	for (auto v : adj[u])
		if (not dfs_num[u]) {
			
			dfs_bride(v, u, next, bridges);


			if (dfs_low[v] > dfs_num[u])
				bridges.emplace_back(u, v); 

			dfs_low[u] =  min(dfs_low[u], dfs_low[v]);

		}else if (v != p)

			dfs_low[u] = min(dfs_low[u], dfs_num[v]);

}

vector<pair<int,int>> bridges(int n){
	vector<pair<int,int>> bridge;

	for (int u = 1, next = 0; u <= n; ++u)
		dfs_bride(u, u, next, bridge);

	return bridge;

}

int main(){
	
	vector<pair<int,int>> bridge;

	bridge = bridges(5+1);
	
	for (auto [a, b]: bridge)
		cout << a << " " << b << endl;

}
