#include<bits/stdc++.h>

using namespace std;

size_t edit_distance( string& a,  string& b){
 
  const size_t oo = 2e9;

  a = " " + a;
  b = " " + b;
 
  vector<vector<size_t>> dp(a.size(), vector<size_t> (b.size(), oo));
 
  for (size_t i = 0; i < a.size(); i++)
    dp[i][0] = i;
 
  for (size_t j = 0; j < b.size(); j++)
    dp[0][j] = j;
 
  for (int i = 1; i < a.size(); i++)
    for (int j = 1; j < b.size(); j++){
      dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1]+1, dp[i-1][j-1] + (a[i] != b[j] ? 1 : 0)});
    }
 
 
  return dp[a.size() - 1][b.size() -1];
 
}

