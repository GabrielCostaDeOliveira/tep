#include<bits/stdc++.h>

using namespace std;

int edit(string a, string b){

  vector<vector<int>> dp(a.size(), vector<int>(b.size()));

  for (size_t i =0; i < a.size(); i++)
    dp[i][0] = 1;

  for (size_t j =0; j < b.size(); j++)
    dp[0][j] = 1;


  for (int i = 1; i < (int) a.size(); i++)
    for (int j = 1; j < (int) b.size(); j++)
      dp[i][j] = min({dp[i][j-1] + 1,dp[i-1][j] + 1, dp[i-1][j-1] + (a[i] == b[j] ? 1 : 0)});


  return dp[a.size()-1][b.size() -1];

}

int main(){
  string a, b;
  cin >> a >> b;

  cout << edit(a, b) << endl;

}


