// Euler's totient function or Euler's phi function is  is the number of integers k in the range 1 ≤ k ≤ n for which the greatest common divisor gcd(n, k) is equal to 1
long long fast_pow(long long a, long long b) {
  if ( b == 0) return 1;
  long long u = fast_pow(a, b/2);
  return b & 1 ? a * u * u :  u * u;
}


long long phi(long long x){
  long long res = 1;

  for ( long long i = 2; i * i  <= x; i++ ){

    int qnt = 0;
    while ( x % i == 0 ){
      qnt++;
      x/= i;
    }

    if (qnt != 0)
      res *= (i - 1)  * fast_pow(i, qnt-1);

  }

  if (x != 1)
    res *= (x - 1);


  return res;

}

