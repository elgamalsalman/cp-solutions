#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, tc, dp[50][50];

ll prop(int l1, int l2) {
  if (l1 < 0 || l2 < 0) return 0;
  if (l1 == 0 && l2 == 0) return 1;
  ll &currCell = dp[l1][l2];
  if (currCell != -1) return currCell;

  if (l1 == l2) {
    currCell = prop(l1 - 1, l2 - 1) + prop(l1 - 1, l2 - 2) + prop(l1 - 2, l2 - 1) + 2 * prop(l1 - 2, l2 - 2);
  } else if (l1 > l2) {
    currCell = prop(l1 - 1, l2) + prop(l1 - 2, l2 - 1);
  } else {
    currCell = prop(l1, l2 - 1) + prop(l1 - 1, l2 - 2);
  }

  return currCell;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n;
    
    memset(dp, -1, sizeof dp);
    cout << prop(n, n) << '\n';
  }
}
