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
