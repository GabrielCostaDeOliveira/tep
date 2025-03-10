#include <vector>

std::vector<long long> sieve(long long n){

  std::vector<bool> is_prime(n, true);

  for (long long i = 2; i*i <= n; i++){
    if (is_prime[i] and i * i <= n)
      for (long long j = i*i; j < n; j+=i )
        is_prime[j] = false;
  }

  std::vector<long long> res;
  for (int i = 2 ;i <= n;i++)
    if (is_prime[i])
      res.push_back(i);

  return res;

}
