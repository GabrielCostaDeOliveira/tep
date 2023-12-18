
#include <bits/stdc++.h>

std::map<long long, long long> fat(long long n){

  std::map<long long, long long> m;

  for (long long i = 2;i*i <= n ;i++){

    long long q = 0;
    while (n % i == 0){
      q++;
      n/=i;
    }

    if (q)
      m[i] = q;
  }

  if ( n != 1)
    m[n] = 1;


  return m;
}
