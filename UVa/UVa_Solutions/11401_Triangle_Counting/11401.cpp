#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, dp[1000005];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  dp[3] = 0;
  for (int i = 4; i < 1e6 + 5; i++) {
    ll j = i - 3;
    ll m = ceil(j / 2.0);
    j *= m;
    j -= (m - 1) * m;
    dp[i] = dp[i - 1] + j;
  }

  while (cin >> n && n >= 3) {
    cout << dp[n] << '\n';
  }
}
