
#include<bits/stdc++.h>

std::vector<std::pair<int, int>> dir8{
  { 1,  0},   
  { 1,  1},   
  { 0,  1},   
  {-1,  1},  
  {-1,  0},  
  {-1, -1}, 
  { 0, -1},  
  { 1, -1}   
};

std::vector<std::tuple<char, int, int>> dir4{
  {'R',  0,  1},   
  {'L',  0, -1},
  {'D',  1,  0},   
  {'U', -1,  0},  
};
