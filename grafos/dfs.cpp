#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj {
	{},
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
	{}           //13

};         
bitset<13+1> visitado;

void dfs(int u){

	if (visitado[u])
		return;
	
	
	cout << u <<" -" ;


	visitado[u] = true;
	 
	for (auto v: adj[u])
				dfs(v);
		
}





int main(){
	dfs(1);

}



