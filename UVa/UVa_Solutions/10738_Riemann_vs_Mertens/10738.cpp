#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int pfCount, n, leastPf[1000050], mu[1000050], M[1000050];
bool isSquareFree;

void sieve() {
  memset(leastPf, -1, sizeof leastPf);
  for (ll i = 2; i <= 1e6; i++) {
    if (leastPf[i] != -1) continue;
    for (ll j = i * i; j <= 1e6; j += i) if (leastPf[j] == -1) leastPf[j] = i;
  }
}

void primeFactorise(int n) {
  if (n == 1) return;
  if (leastPf[n] == -1) {
    pfCount++;
  } else {
    int currPfCount = 0, pf = leastPf[n];
    for (;n % pf == 0; currPfCount++) n /= pf;
    if (currPfCount > 1) isSquareFree = 0;
    pfCount += currPfCount;
    primeFactorise(n);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve();
  mu[0] = 0; mu[1] = 1;
  for (int i = 2; i <= 1e6; i++) {
    isSquareFree = 1;
    pfCount = 0;
    primeFactorise(i);
    if (!isSquareFree) mu[i] = 0;
    else if (pfCount % 2) mu[i] = -1;
    else mu[i] = 1;
  }

  partial_sum(mu, mu + 1000000, M);

  while (cin >> n && n) {
    cout << setw(8) << n << setw(8) << mu[n] << setw(8) << M[n] << '\n';
  }
}
