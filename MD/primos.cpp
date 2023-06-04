#include <bits/stdc++.h>
#define MAX 100

using ll = long long;

using namespace std;

bool isPrime(ll x){

  if (x == 1)
    return false;

  if (x == 2)
    return true;

  for ( ll i = 2; i*i <= x  ;i++){

    if ( x % i == 0 ){
      return false;
    }
  }


  return true;

}

ll num_div(ll n){

  ll res = 1;


  for ( int i = 2; i*i <=n ;i++){

    ll p = 0;
    while (n % i == 0){
      p++;
      n/= i;
    }

   res *= (p + 1);
    
  }


  if (n != 1)
    res *= 2;


  return res;

}

vector<bool> crivo(int x) {
    vector<bool> isPrime(x + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= x; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= x; j += i) {
                isPrime[j] = false;
            }
        }
    }

    return isPrime;
}

