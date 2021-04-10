#include<bits/stdc++.h>

using namespace std;

#define MODVAL 100000000

int	n, n1, n2, k1, k2, dp[105][105][2];

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n1 >> n2 >> k1 >> k2;
	n = n1 + n2;
	memset(dp, 0, sizeof dp);
	dp[0][0][0] = dp[0][0][1] = 1;
	for (int i = 0; i <= n1; i++) {
		for (int j = 0; j <= n2; j++) {
			//cerr << "// i : " << i << ", j : " << j << '\n';
			for (int k = 1; k <= k1 && i + k <= n1; k++) {
				//cerr << "// going from (" << i << ", " << j << ") to (" << i + k << ", " << j << ")\n";
				dp[i + k][j][0] += dp[i][j][1];
				dp[i + k][j][0] %= MODVAL;
			}

			for (int k = 1; k <= k2 && j + k <= n2; k++) {
				//cerr << "// going from (" << i << ", " << j << ") to (" << i << ", " << j + k << ")\n";
				dp[i][j + k][1] += dp[i][j][0];
				dp[i][j + k][1] %= MODVAL;
			}
		}
	}

	cout << (dp[n1][n2][0] + dp[n1][n2][1]) % MODVAL << '\n';
}
