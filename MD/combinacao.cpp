#include <bits/stdc++.h>

using ll = long long int;
using namespace std;

void triangulo(int n){

	vector<vector<ll>> dp (n+1, vector<ll>(n+1,0));

for (int i = 0; i <= n; i++){
	dp[i][0] = dp[i][i] = 1;

	for (int j = 1; j < i; ++j)
		dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
}

cout <<  "-------" << endl;

	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= i; j++)
			cout << setw(3) << dp[i][j] << " ";

		cout << endl << endl;

	}
}


ll binom_1(int n, int m){
	vector<vector<ll>> dp (n+1, vector<ll>(n+1, 0));

	for (int i = 0; i <= n; i++){
		dp[i][i] = dp[i][0] = 1;

		for (int j = 1; j < i; j++)
			dp [i][j] = dp[i-1][j] + dp[i-1][j-1];
	}

	return dp[n][m];
}

ll binom_2(int n, int m){
	if (m > n)
		return 0;

	vector<ll> dp(m+1, 0);
	dp[0] = 1;

	for (int i = 1; i <= n; i++)
		for (int j = m; j > 0; j--)
			dp[j] = dp[j] + dp[j-1];

	return dp[m];

}

int main(){
	int n, m;
	cin >> n >> m;

	triangulo(n);
	
	cout << binom_2(n, m) << endl;

	
}
