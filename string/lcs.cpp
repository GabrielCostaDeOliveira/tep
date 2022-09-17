#include <bits/stdc++.h>
 
using namespace std;
 
const int oo = 1000000000;
 
int lsc(const string &s, const string &t){
    int n = s.size(), m = t.size();
 
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
 
    for (int i = 1; i <= n; i++ )
        for (int j = 1; j <= m; j++){
            dp[i][j] = max( {dp[i][j-1], dp[i-1][j],dp[i-1][j-1]  +(s[i-1] == t[j-1] ? 1 : -oo) } );
        }
 
 
/// for (int i = 0; i < n +1; i++ ){
///     for (int j = 0; j < m+1; j++)
///         cout << dp[i][j] << " ";
///     cout << endl;
///         
/// }
 
 
 
    return dp[n][m];
 
}
