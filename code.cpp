#include <bits/stdc++.h>

using namespace std;

int main(){
	long long soma = 0, aux = 4;

	for (int i = 1; i <=10 ; i++){
		soma += aux;
		cout << aux  << " ";
		aux *= 2;
	}

	cout << endl << soma << endl;

		
}
