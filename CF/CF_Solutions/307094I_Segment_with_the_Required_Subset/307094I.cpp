#include <bits/stdc++.h>

using namespace std;

int	minLen = 1e8, dp[100'050][1050], a[100'050], n, s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;

	for (int i = 0; i < n; i++) cin >> a[i];

	memset(dp, -1, sizeof dp);
	dp[0][a[0]] = 0;
	for (int i = 0; i < n - 1; i++) {
		dp[i + 1][a[i + 1]] = i + 1;
		for (int subsetSum = 1; subsetSum <= s; subsetSum++) {
			if (dp[i][subsetSum] == -1) continue;
			dp[i + 1][subsetSum] = max(dp[i + 1][subsetSum], dp[i][subsetSum]);
			if (subsetSum + a[i + 1] <= s) dp[i + 1][subsetSum + a[i + 1]] = max(dp[i + 1][subsetSum + a[i + 1]], dp[i][subsetSum]);
		}
	}

	for (int i = 0; i < n; i++) {
		if (dp[i][s] == -1) continue;
		minLen = min(minLen, i - dp[i][s] + 1);
	}

	cout << (minLen == 1e8 ? -1 : minLen) << '\n';
}
