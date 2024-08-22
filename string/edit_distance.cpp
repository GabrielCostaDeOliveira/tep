#include<bits/stdc++.h>

using namespace std;

int edit_distance(const string& a, const string& b) {
 
 
    const int ADD = 1;
    const int REMOVE = 1;
    const int CHANGE = 1;
 
 
    size_t m =  a.size();
    size_t n =  b.size();
 
    
    vector<vector<int>> memo(m + 1, vector<int>(n + 1));
 
    for (size_t i = 0; i <= m; i++)
      memo[i][0] = i*REMOVE;
   
    for (size_t j = 0; j <= n; j++)
      memo[0][j] = j*ADD;
 
    for (size_t i = 1; i <= m; i++) 
        for (size_t j = 1; j <= n; j++) 
          memo[i][j] = min({memo[i-1][j]  + REMOVE, memo[i][j-1] + ADD,  memo[i-1][j-1] + (a[i-1] == b[j-1] ? 0 : CHANGE) });
          

 
    return memo[m][n];
}


