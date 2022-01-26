#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long int;

ll mdc(ll a, ll b){    // a >= b. b > 0
	return b ? mdc(b, a%b) : a;
}

int mdc2(int a, int b ){
	int resto;

	do{
		resto = a % b;

		cout << resto << endl;

		a =b;
		b = resto;

	}while(resto != 0);

	return a;
}


int main(){
	int a, b;
	cout << " divite dois numeros" << endl;
	cin >> a >> b;
	cout << mdc(a, b) << " " << mdc(a, b) << " " << __gcd(a, b);

}
