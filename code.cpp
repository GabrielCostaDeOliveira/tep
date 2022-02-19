#include<bits/stdc++.h>

using namespace std;
string solve (vector<pair<int,int>> p1, vector<pair<int,int>> p2){
   for (auto c1 : p1)
      for (auto c2 : p2 )
         if (c1 == c2)
            return "Yes";
   return "No";
}

vector<pair<int,int>> vari { { 2,  1}, 
                             { 1,  2}, 
                             {-1,  2}, 
                             {-2,  1}, 
                             {-2, -1}, 
                             {-1, -2}, 
                             { 1, -2},
                             { 2, -1}};

int main(){
   pair<int,int> r1, r2;
   cin >> r1.first >> r1.second >> r2.first >> r2.second;



   vector<pair<int, int>> p1, p2;
   for (auto [dx, dy] : vari)
      p1.push_back({r1.first + dx, r1.second + dy});

   for (auto [dx, dy] : vari)
      p2.push_back({r2.first + dx, r2.second + dy});



   cout << solve (p1, p2) << endl;

}
