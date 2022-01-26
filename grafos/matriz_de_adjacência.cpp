#include <bits/stdc++.h>
using namespace std;

const int N { 6 };
int A [N + 1][N+1]; //somando para não usar o indice 0

int main(){
	//leitura
	for (int i = 1; i <= 6; i++)
		for (int j = 1; j <= 6; j++)
			cin >> A[i][j];

	//imprimir 
	for (int i = 1; i <= 6; i++){
		for (int j = 1;  j <= 6; j++)
			cout << A[i][j] << " ";
		cout << "\n";
	}

}
