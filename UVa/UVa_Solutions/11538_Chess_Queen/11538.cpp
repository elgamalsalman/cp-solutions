#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll m, n, dp[1000050];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  dp[0] = 0;
  for (ll i = 1; i <= 1e6; i++) {
    dp[i] = dp[i - 1] + i * (i - 1);
  }

  while (cin >> m >> n && m) {
    ll ans = m * n * (n - 1) + n * m * (m - 1);
    ll diagCount = abs(m - n) + 1;
    ll diagLen = min(m, n);
    ans += 2 * diagCount * diagLen * (diagLen - 1);
    ans += 4 * dp[diagLen - 1];
    cout << ans << '\n';
  }
}
