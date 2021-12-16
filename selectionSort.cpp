#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> & vec, int tam){
	for (int i = 0; i < tam ; i++){
		int mi = i;

		for (int j = i + 1; j < tam; j++ )  
			if (vec[j]<vec[mi])
				mi = j;
		
			int aux  = vec[i];
			vec[i] = vec[mi];
			vec[mi] = aux;
	}

}

int main(){
	vector<int> vec = {-6, 0, 35, -2, 4}; 

	selectionSort(vec,vec.size());

	for (auto ele : vec)
		std::cout << ele << " ";

	std::cout << std::endl;

}
