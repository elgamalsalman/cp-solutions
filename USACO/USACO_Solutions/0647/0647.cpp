#include <bits/stdc++.h>

using namespace std;

int dp[250][250], a[250], n, ans;

int calcMax(int l, int r) {
  int &currCell = dp[l][r]; 
  if (currCell != -1) return currCell;

  if (l == r) return currCell = a[l];

  currCell = -2;

  for (int k = l + 1; k <= r; k++) {
    int lVal = calcMax(l, k - 1);
    int rVal = calcMax(k, r);
    if (lVal == -2 || lVal != rVal) continue;
    currCell = max(currCell, lVal + 1);
  }

  return currCell;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  freopen("248.in", "r", stdin);
  freopen("248.out", "w", stdout);

  memset(dp, -1, sizeof dp);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      calcMax(i, j);
    }
  }

  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++)
      ans = max(ans, dp[i][j]);

  cout << ans << '\n';
}
