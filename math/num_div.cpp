long long num_div(long long n){

  long long res = 1;


  for ( int i = 2; i*i <=n ;i++){

    long long p = 0;
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
