#include <iostream>


using namespace std;


int mdc(int num1, int num2 ){
	int resto;

	do{
		resto = num1 % num2;

		cout << resto << endl;

		num1 = num2;
		num2 = resto;

	}while(resto != 0);

	return num1;
}


int main(){
	cout << mdc(6*7, 9*9);

}
