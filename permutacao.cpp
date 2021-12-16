#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> a (5);


	iota(a.begin(), a.end(), 1);

	sort(a.rbegin(), a.rend());

	do{
		for (size_t i = 0; i < a.size(); i++){
			cout << a[i] << (i + 1 == a.size() ? '\n' : ' ');
		}
	}while (prev_permutation (a.begin(), a.end()));

}
