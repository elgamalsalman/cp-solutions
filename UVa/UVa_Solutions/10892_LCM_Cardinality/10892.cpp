#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int C, N;
bitset<100050> isPrime;
vi primes;

void sieve() {
  isPrime.set();
  isPrime[1] = 0;
  for (ll i = 2; i <= 1e5; i++) {
    if (!isPrime[i]) continue;
    primes.push_back(i);
    for (ll j = i * i; j <= 1e5; j += i) {
      isPrime[j] = 0;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve();

  while (cin >> N && N) {
    int originalN = N, primeFactorCount = 0;
    C = 1;
    for (int primeFactor : primes) {
      int i = 0;
      if (!(N % primeFactor)) primeFactorCount++;
      for (; !(N % primeFactor); i++) N /= primeFactor;
      C *= 1 + 2 * i;
      if (N == 1) break;
    }
    cout << originalN << ' ' << (C + 1) / 2<< '\n';
  }
}
