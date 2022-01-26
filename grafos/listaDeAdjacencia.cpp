#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

vector<ii> adj[6 + 1] ; 


int main(){
	int aux;

//leitura	
	for (int i = 1 ; i <= 6; i++)
		for (int j = 1; j <= 6; j++){
			cin >> aux;
			cin.ignore();

			adj[i].at(j).first  = j;
			adj[i].at(j).second = aux;
		}

	for( int u =1; u <= 6; ++u ){
		cout << u << ':';

		for(auto [v, w] : adj[u])
			cout << " (" << v << ", "<< w <<")";
	}

}
