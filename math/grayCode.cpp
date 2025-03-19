#include <bits/stdc++.h>

using namespace std;

vector<int> grayCode(int n){
	vector<int> res;

	for (int i = 0; i < 1<<n; i++)
		res.push_back(i ^ (i >> 1));


	return res;
}

int MSB(int n){
	int i;
	for (i = 1; i <= n and i < 1 <<31 ; i<<=1);
	return i>>1;
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		for (auto j : grayCode(i))
			cout << j << " ";
		cout << endl;
	}
	

}
