#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;

vector<vector<int>> adj = { 
													 {},
													 {2},
													 {1, 3, 5 },
													 {2},
													 {},
													 {2},
													 {7},
													 {6} 
															};


bitset<MAX> vistado ;

void dfs(int u){
	if (vistado[u])
		return;

	cout << u << "- ";
	vistado[u] = true;

	for (int v: adj[u])
		dfs(v);
}

int main(){
	int cont {0};
	for ( int i = 1; i< adj.size(); i++ )
		if(not vistado[i]){
			cout <<endl<< "visitando componente " << ++cont << endl;
			dfs(i);
		}


	
}
