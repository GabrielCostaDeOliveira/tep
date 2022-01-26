#include <bits/stdc++.h>

using namespace std;

vector<int> mudancaDebase(int num, int base){
	vector<int> novo;
	while (num % base > base){
		novo.push_back(num/base);
		num %= base;
	}


	return novo;
}


int main(){
	for (int i = 2; i<= 9; i++){
		for (auto v : mudancaDebase(100,i))
				cout << v << endl;

		cout << endl;
	}

}
