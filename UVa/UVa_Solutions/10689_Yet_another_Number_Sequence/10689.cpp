#include<bits/stdc++.h>

using namespace std;

int n, m, tc, c, fib[300050];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> fib[0] >> fib[1] >> n >> m;
    m = pow(10, m);

    fib[0] %= m;
    fib[1] %= m;

    for (c = 2; ; c++) {
      fib[c] = (fib[c - 1] + fib[c - 2]) % m;

      if (fib[c - 1] == fib[0] && fib[c] == fib[1]) break;
    }

    n %= c - 1;
    cout << fib[n] << '\n';
  }
}
