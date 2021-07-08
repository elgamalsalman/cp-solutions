#include <bits/stdc++.h>

using namespace std;

int	dp[1000][1000], distances[1000], N, K;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> N >> K) {

		for (int i = 0; i < N + 1; i++) cin >> distances[i];

		for (int i = 0; i <= N + 1; i++) fill(dp[i], dp[i] + K + 2, 1e9);
		dp[0][0] = 0;
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= K; j++) {
				if (dp[i][j] == 1e9) continue;
				dp[i][j + 1] = min(dp[i][j], dp[i][j + 1]);
				int currDis = 0;
				for (int k = i + 1; k <= N + 1; k++) {
					currDis += distances[k - 1];
					dp[k][j + 1] = min(dp[k][j + 1], max(dp[i][j], currDis)); 
				}
			}
		}

		cout << dp[N + 1][K + 1] << '\n';
	}
}
