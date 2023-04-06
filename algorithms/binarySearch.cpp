#include <bits/stdc++.h>


long long lowerBound(long long x, std::function<long long(long long)> f){

  long long a = 0, b = 5'223'372'036'854'775'807;

  while ( a < b ){
    long long mid = a + (b-a)/2;

    if ( f(mid) >= x )
      b = mid;
    else 
      a = mid + 1;
  }


  return a;

}
