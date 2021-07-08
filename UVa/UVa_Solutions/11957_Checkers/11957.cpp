#include <bits/stdc++.h>

using namespace std;

#define MODVAL 1000007

int	tcNum, dp[105][105], waysCount, tc, N;
char	grid[105][105];

bool isEmpty(int r, int c) {
	if (r >= N || r < 0 || c >= N || c < 0) return 0;
	return (grid[r][c] == '.');
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		waysCount = 0;
		memset(dp, 0, sizeof dp);
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin.ignore();
			for (int j = 0; j < N; j++) {
				grid[i][j] = cin.get();
				if (grid[i][j] == 'W') dp[i][j] = 1;
			}
		}

		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < N; j++) {
				if (isEmpty(i - 1, j - 1)) {
					dp[i - 1][j - 1] = (dp[i - 1][j - 1] + dp[i][j]) % MODVAL;
				} else if (isEmpty(i - 2, j - 2)) {
					dp[i - 2][j - 2] = (dp[i - 2][j - 2] + dp[i][j]) % MODVAL;
				}

				if (isEmpty(i - 1, j + 1)) {
					dp[i - 1][j + 1] = (dp[i - 1][j + 1] + dp[i][j]) % MODVAL;
				} else if (isEmpty(i - 2, j + 2)) {
					dp[i - 2][j + 2] = (dp[i - 2][j + 2] + dp[i][j]) % MODVAL;
				}
			}
		}

		for (int i = 0; i < N; i++) waysCount += dp[0][i];

		cout << "Case " << ++tcNum << ": " << waysCount % MODVAL << '\n';
	}
}
