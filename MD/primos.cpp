#include <bits/stdc++.h>
#define MAX 100


using namespace std;

// is_prime é o(n), muito simples e muito custosa;

bool is_prime (int n){


	if (n < 2)
		return false;

	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return true;


	return false;
}

//is_prime2 reduz o número de operação, mas não reduz a complexidade

bool is_prime2 (int n){

	if (n < 2)
		return false;

	if (n == 2)
		return true;

	if (n % 2 == 0)
		return false;

	for (int i = 3; i < n; i+=2) // apenas numeros impares chegam aqui 
		if (n % i == 0)
			return false;

	return true;

}

//usando o fato de que d < sqrt(n), diminuimos a complexidade para o(sqrt(n))

bool is_prime3 (int n){

// is_prime o (sqrt(n))
// observe que não foi usado a função sqrt, assim a aaritimérica ficou restrita ao numeros inteiros evitando erros de arrendodamento

	if (n < 2)
		return false;

	if (n == 2)
		return true;

	if (n % 2 == 0)
		return false;

	for (int i = 3; i * i <= n; i+=2) // apenas numeros impares chegam aqui 
		if (n % i == 0)
			return false;

	return true;

}


vector<int> primes (int n){

	vector<int> ps;

	for (int i = 2; i <= n; i++)
		if (is_prime3(i))
			ps.push_back(i);

	return ps;
}

//compolexidade o(n*log(n))
vector<int> primes2 (int n){
	vector<int> ps;
	bitset<MAX> sieve;
	sieve.set();
	sieve[1] = false;

	for (int i = 2; i <= n; i++){
		if (sieve[i]){
			ps.push_back(i);

			for (int j = 2*i; j <= n; j+=i)
				sieve[j] = false;
		}
	}

	return ps;

}

// não diminui a complexidade, mas reduz o numeor de instruçãoes
//
vector<int> primes3 (int n){
	bitset<MAX> sieve;
	vector<int> ps {2};
	sieve.set();

	for (int i = 3; i <= n; i += 2) {
		if (sieve[i]){
			ps.push_back(i);

			for (int j = 2*i; j <= n; j += i)
				sieve[j] = false;
		}
	}
	return ps;
}

vector<long long> primes4(long long n){
	bitset<MAX> sieve;
	vector<long long> ps {2};
	sieve.set();

	for (long long i = 3; i <= n; i += 2){
		if (sieve[i]){
			ps.push_back(i);

			for (long long j = i*i; j <= n; j += 2*i)
				sieve[j] = false;
		}
	}

	return ps;
}


int main(){

}
