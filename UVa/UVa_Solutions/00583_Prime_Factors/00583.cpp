#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

ll n;
vi primes;
bitset<100050> isPrime;

void sieve(ll n) {
  isPrime.set();
  isPrime[1] = 0;
  for (ll i = 2; i <= n; i++) {
    if (!isPrime[i]) continue;
    primes.push_back(i);
    for (ll j = i * i; j <= n; j += i) isPrime[j] = 0;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve(100000);

  while (cin >> n && n) {
    cout << n << " = ";
    if (n < 0) {
      cout << "-1 x ";
      n = -n;
    }
    
    bool firstFactor = 1;
    for (ll prime : primes) {
      while (!(n % prime)) {
	if (firstFactor) firstFactor = 0;
	else cout << " x ";
	cout << prime;
	n /= prime;
      }

      if (n == 1) break;
    }

    if (firstFactor) cout << n;

    cout << '\n';
  }
}
