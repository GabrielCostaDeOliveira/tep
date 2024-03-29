#include<bits/stdc++.h> 

template<typename T>
T kadane(const std::vector<T> &v){

  T current = v[0], res = v[0];

  for (size_t i = 1; i < v.size(); i++){

    current = max(v[i], current + v[i]);

    res = max(res, current);
    
  }

  return res;

}
