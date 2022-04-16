#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long int;

ll gcd(ll a, ll b){    // a >= b. b > 0
	return b ? gcd(b, a%b) : a;
}

int gcd2(int a, int b ){
	int resto;

	do{
		resto = a % b;

		cout << resto << endl;

		a =b;
		b = resto;

	}while(resto != 0);

	return a;
}

int lcd(int a, int b){
	return a*b/gcd(a, b);
}


int main(){
	int a, b;
	cout << " digite dois numeros" << endl;
	cin >> a >> b;
	cout << "gcd = " << __gcd(a, b) << endl << "lcd = " << lcd(a, b) << endl;

}
