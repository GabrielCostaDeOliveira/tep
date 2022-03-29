#include <bits/stdc++.h>

#define MAX 100

using namespace std;

vector<vector<int>> adj {
	{},
	{2},
	{1,3,4,6},
	{2},
	{2, 6},
	{6},
	{2, 4}
};

bitset<MAX> visitado;

bool temCiclo(int u, int p= -1){
	if(visitado[u])
		return false;

	visitado[u] = true;

	for (int v : adj[u]){
		
		if (visitado[v] and v != p)
			return true;

		if (temCiclo(v, u))
		return true;
	}

	return false;
}

int main(){
	cout << temCiclo(1) << endl;

}
