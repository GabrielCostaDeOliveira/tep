#include <bits/stdc++.h>

using namespace std;

int mdc (int a, int b){
	if (a == 0)
		return b;
	return mdc(b % a,a);


}

int main(){
	cout  << mdc(12, 24) << endl;

}
