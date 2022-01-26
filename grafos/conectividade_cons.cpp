#include <bits/stdc++.h>
	
using namespace std;

vector<vector<int>> adj (5e5 + 10);
bitset<500000 + 10> visitado;

void dfs(int u){
	if (visitado[u])
		return;
		
	visitado[u]=true;

	for (int v:adj[u])
		dfs(v);

}


int main(){
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++){
		int k;
		cin >>k;

		int rede[n+10];
		for (int j = 1; j <= k; j++){
			cin >> rede[j];
		}

		if (n)
			for (int y = 2; y<=k; y++){
				adj[rede[y-1]].push_back(rede[y]);
				adj[rede[y]].push_back(rede[y-1]);
			}
		
	}

	for(int i = 1; i <=n; i++){
		visitado.reset();
		dfs(i);
		cout << visitado.count() << " ";

	}
	cout << endl;

}
