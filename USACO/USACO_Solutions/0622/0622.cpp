#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int dp[105][10][105], n, k;
vi endingState;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  freopen("cbarn2.in", "r", stdin);
  freopen("cbarn2.out", "w", stdout);

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    endingState.push_back(tmp);
  }

  int ans = 1e9;
  for (int i = 0; i < n; i++) {
    memset(dp, -1, sizeof dp);
    dp[0][1][0] = 0;
    for (int ind = 0; ind < n - 1; ind++) {
      for (int doorCount = 1; doorCount <= k; doorCount++) {
	for (int doorInd = 0; doorInd <= ind; doorInd++) {
	  int &currCell = dp[ind][doorCount][doorInd];
	  if (currCell == -1) continue;

	  int &newCell1 = dp[ind + 1][doorCount][doorInd];
	  if (newCell1 == -1) newCell1 = 1e9;
	  newCell1 = min(newCell1, currCell + endingState[ind + 1] * (ind + 1 - doorInd));

	  int &newCell2 = dp[ind + 1][doorCount + 1][ind + 1];
	  if (newCell2 == -1) newCell2 = 1e9;
	  newCell2 = min(newCell2, currCell);
	}
      }
    }

    for (int i = 0; i < n; i++) if(dp[n - 1][k][i] != -1) ans = min(ans, dp[n - 1][k][i]);

    rotate(endingState.begin(), endingState.begin() + 1, endingState.end()); 

  }

  cout << ans << '\n';
}
