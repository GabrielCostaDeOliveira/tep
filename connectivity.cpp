#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> estradas (2e5 + 10);
vector<vector<int>> ferrovias (2e5 + 10);

bitset<100> visidado;

void dfs(int u, const vector<vector<int>> & adj){
	if (visidado[u])
		return;
		
	cout << u << " -";
	visidado[u]= true;

	for (int v: adj[u])
		dfs(v,adj);
}

int main(){
	int n, k, l;
	cin >> n >> k >> l; 

	for (int u = 1; u <= k; u++){
		int i, j ; cin >> i >> j;

		estradas[i].push_back(j);
		estradas[j].push_back(i);
	}

	for (int u = 1; u <= l; u++){
		int i, j ; cin >> i >> j;

		ferrovias[i].push_back(j);
		ferrovias[j].push_back(i);
	}

	int cont =0;
	for (int u = 1 ; u<=n; u++)
		
		if (not visidado[u]){
			cout << endl<<"visitando componente "<< ++cont<< endl;
			dfs(u,ferrovias);
		}


	
}
