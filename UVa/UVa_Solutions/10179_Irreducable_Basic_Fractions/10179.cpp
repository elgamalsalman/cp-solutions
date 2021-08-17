#include <bits/stdc++.h>

using namespace std;

#define MAX_PRIME 32000

typedef long long ll;
typedef vector<ll> vi;

ll n, ans;
bitset<MAX_PRIME> isPrime;
vi primes;

void sieve() {
  isPrime.set();
  isPrime[1] = 0;
  for (ll i = 2; i < MAX_PRIME; i++) {
    if (!isPrime[i]) continue;
    primes.push_back(i);
    for (ll j = i * i; j < MAX_PRIME; j += i) isPrime[j] = 0;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve();
  while (cin >> n && n) {
    ans = n;
    for (ll prime : primes) {
      if (prime > n || n == 1) break;
      if (n % prime == 0) ans *= (1 - 1.0/prime);
      while (n % prime == 0) n /= prime;
    }
    if (n != 1) ans *= (1 - 1.0/n);
    cout << ans << '\n';
  }
}
