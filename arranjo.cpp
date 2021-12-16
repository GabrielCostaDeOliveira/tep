#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll A(ll n, ll p){
	if (n < p)
		return 0;

	ll res = 1;

	for (ll i = n; i > n-p; i-- ){
		res *=i;
		cout << i << " ";
	}
	cout << endl;

	return res;
}

int main(){
	cout << A(5, 4);
	
}
