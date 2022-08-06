#include <bits/stdc++.h>

using namespace std;

long long factorial(long long i){
	if (i == 0)
		return 0;
	
	return i*factorial(i-1);
}

template<typename T>
long long permutations(const vector<T>& A){
	map<T, int> hist;

	for (auto a : A)
		++hist[a];

	long long res = factorial(A.size());

	for (auto [_, ni] : hist)
		res /= factorial(ni);

	return res;
}

//enumerando permutações O(n * n!)
void permutations_list(vector<int> num){
	num = {5, 3, 2, 1, 4};

	sort(num.begin(), num.end());

	do {
		for (size_t i = 0;  i < num.size(); i++)
			cout << num[i] << ( i + 1 == num.size() ? '\n' : ' ');
	}while(next_permutation(num.begin(), num.end()));
}

int main(){

}
