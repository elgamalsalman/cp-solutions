#include <bits/stdc++.h>

using namespace std;

int	prefixMax[100050], r, n, t[100050], x[100050], y[100050], dp[100050];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> n;
	for (int i = 0; i < n; i++) cin >> t[i] >> x[i] >> y[i];

	memset(dp, 0, sizeof dp);
	for (int i = 0; i < n; i++) {
		if (abs(x[i] + y[i] - 2) <= t[i]) dp[i] = 1;
		for (int j = i - 1; j >= 0 && j >= i - 2*r; j--) {
			if (!dp[i] || abs(x[j] - x[i]) + abs(y[j] - y[i]) > abs(t[j] - t[i])) continue;
			dp[i] = max(dp[i], dp[j] + 1);
		}
		if (i - 2*r > 0) {
			dp[i] = max(dp[i], prefixMax[i - 2*r] + 1);
		}
		if (!i || prefixMax[i - 1] < dp[i]) {
			prefixMax[i] = dp[i];
		} else prefixMax[i] = prefixMax[i - 1];
	}

	cout << prefixMax[n - 1] << '\n';
}
