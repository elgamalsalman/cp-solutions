#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int ans[1000050], n, leastPF[1000050], LCMFactorisation[1000050], LSDigit = 1;
vi primes;

void sieve() {
  memset(leastPF, -1, sizeof leastPF);
  for (ll i = 2; i <= 1e6; i++) {
    if (leastPF[i] != -1) continue;
    primes.push_back(i);
    for (ll j = i * i; j <= 1e6; j += i) if (leastPF[j] == -1) leastPF[j] = i;
  }
}

void updatePFCount(int pf, int pfCount) {
  if (pfCount > LCMFactorisation[pf]) {
    if (pf == 2 || pf == 5) {
      LCMFactorisation[pf] = pfCount;

      // Number of 2 and 5 prime factors to be cancelled
      int cancelCount = min(LCMFactorisation[2], LCMFactorisation[5]);

      LSDigit = 1;
      for (int i = 2; i < 1e6; i++) {
	int j = 0;
	if (i == 2 || i == 5) j = cancelCount;
	for (; j < LCMFactorisation[i]; j++) {
	  LSDigit *= i;
	  LSDigit %= 10;
	}
      }
    } else {
      for (int i = 0; i < pfCount - LCMFactorisation[pf]; i++) {
	LSDigit *= pf;
	LSDigit %= 10;
      }

      LCMFactorisation[pf] = pfCount;
    }
  }
}

void primeFactorise(int n) {
  //cerr << "// primeFactorise(" << n << ")\n";
  //cerr << "// leastPF[" << n << "] : " << leastPF[n] << '\n';
  int pf, pfCount;
  if (leastPF[n] == -1) {
    pf = n;
    pfCount = 1;
  } else {
    pf = leastPF[n];
    for (pfCount = 0; !(n % pf); pfCount++) n /= pf;
    primeFactorise(n);
  }

  updatePFCount(pf, pfCount);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(LCMFactorisation, 0, sizeof LCMFactorisation);

  sieve();
  for (int i = 1; i <= 1e6; i++) {
    //cerr << "// i : " << i << '\n';
    primeFactorise(i);
    //for (int i = 0; i < 130; i++) {
    //  if (LCMFactorisation[i]) cerr << "// {" << i << ", " << LCMFactorisation[i] << "}\n";
    //}
    ans[i] = LSDigit;
  }

  while (cin >> n && n) {
    //cerr << "// " << n << " : ";
    cout << ans[n] << '\n';
  }
}
