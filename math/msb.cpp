long long msb(long long a){

  long long res = 0;

  while (a){
    res++;
    a>>=1;
  }

  return res;
}
