#include <bits/stdc++.h>

using namespace std;

int	n, a[105], b[105], waterSum;
double	dp[2][105][10050];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
	waterSum = accumulate(b, b + n, 0);

	for (int i = 0; i < 2; i++) for (int k = 0; k < 105; k++) for (int c = 0; c < 10050; c++) dp[i][k][c] = -1;

	dp[0][0][0] = 0;
	dp[0][1][a[0]] = b[0];
	int dpLayer = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int k = 0; k <= n; k++) {
			for (int c = 0; c < 10050; c++) {
				if (dp[dpLayer][k][c] == -1) continue;
				dp[!dpLayer][k][c] = max(dp[!dpLayer][k][c], dp[dpLayer][k][c]);
				dp[!dpLayer][k + 1][c + a[i + 1]] = max(dp[!dpLayer][k + 1][c + a[i + 1]], dp[dpLayer][k][c] + b[i + 1]);
			}
		}

		dpLayer = !dpLayer;
	}


	for (int k = 1; k <= n; k++) {
		double ans = 0;
		for (int c = 0; c < 10050; c++) {
			if (dp[dpLayer][k][c] == -1) continue;
			double currAns = min((double) c, dp[dpLayer][k][c] + (waterSum - dp[dpLayer][k][c]) / 2.0);
			if (currAns > ans) ans = currAns;
		}
		cout << ans << " \n"[k == n];
	}
}
