#include <vector>

std::vector<long long> sieve(long long n){

  std::vector<bool> is_prime(n, true);
  std::vector<long long> prime;

  for (long long i = 2; i*i <= n; i++)
    if (is_prime[i] and i * i <= n){

      prime.push_back(i);

      for (long long j = i*i; j < n; j+=i )
        is_prime[j] = false;
    }

  return prime;

}
