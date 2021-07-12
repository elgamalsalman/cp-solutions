#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

enum	{south, east, west};
ll	tcNum, dp[100][100][10][4], N, K, grid[100][100];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> N >> K && (N || K)) {
		for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) cin >> grid[i][j];

		for (int i = 0; i < 100; i++) for (int j = 0; j < 100; j++) for (int k = 0; k < 6; k++) for (int l = 0; l < 3; l++) dp[i][j][k][l] = -1e18;
		dp[1][1][grid[1][1] < 0][east] = grid[1][1];

		for (int i = 1; i <= N; i++) {
			for (int l = 0; l < 3; l++) {
				for (int j = (l == west ? N : 1); (l == west ? j >= 1 : j <= N); (l == west ? j-- : j++)) {
					for (int k = 0; k <= 5; k++) {
						if (dp[i][j][k][l] == -1e18) continue;
						if (l != west && j != N) {
							int newK = k + (grid[i][j + 1] < 0);
							if (newK <= K) {
								ll &newCell = dp[i][j + 1][newK][east];
								newCell = max(newCell, dp[i][j][k][l] + grid[i][j + 1]);
							}
						}
						
						if (l != east && j != 1) {
							int newK = k + (grid[i][j - 1] < 0);
							if (newK <= K) {
								ll &newCell = dp[i][j - 1][newK][west];
								newCell = max(newCell, dp[i][j][k][l] + grid[i][j - 1]);
							}
						}

						if (i != N) {
							int newK = k + (grid[i + 1][j] < 0);
							if (newK <= K) {
								ll &newCell = dp[i + 1][j][newK][south];
								newCell = max(newCell, dp[i][j][k][l] + grid[i + 1][j]);
							}
						}
					}
				}
			}
		}

		ll maxSum = -1e18;
		for (int i = 0; i <= K; i++) for (int j = 0; j < 3; j++)  maxSum = max(maxSum, dp[N][N][i][j]);
		
		cout << "Case " << ++tcNum << ": ";
		if (maxSum == -1e18) cout << "impossible\n";
		else cout << maxSum << '\n';
	}
}
