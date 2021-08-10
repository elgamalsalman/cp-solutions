#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int n;
bitset<1000050> isPrime;
vi primes;

void sieve() {
  isPrime.set();
  isPrime[1] = 0;
  for (ll i = 2; i < 1e6; i++) {
    if (!isPrime[i]) continue;
    primes.push_back(i);
    for (ll j = i * i; j <= 1e6; j += i) isPrime[j] = 0;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve();

  while (cin >> n && n) { 
    int a, b;
    for (int prime : primes) {
      a = prime;
      assert(a < n);
      b = n - a;
      if (binary_search(primes.begin(), primes.end(), b)) break;
    }
    cout << n << " = " << a << " + " << b << '\n';
  }
}
