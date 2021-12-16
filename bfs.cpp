#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj {{},
												{2, 3},      //1
												{4, 5},      //2
												{6},         //3
												{},          //4
												{2,6,8, 9},  //5
												{3,5,7, 10}, //6
												{},          //7
                        {11},        //8
												{5,10},      //9
												{9, 6},      //10
												{12, 13},    //11
												{},          //12
												{}};         //13

bitset<14> colocado_na_lista;

void bfs(int u){
	queue<int> q;
	q.push(u);

	while (not q.empty()){
		int u = q.front(); q.pop();

		cout << u << "- ";
		for(int v : adj[u])
			if (not colocado_na_lista[v]){
				colocado_na_lista[v] = true; 
				q.push(v);
			}
	}
}
int main(){
	bfs(1);
}
