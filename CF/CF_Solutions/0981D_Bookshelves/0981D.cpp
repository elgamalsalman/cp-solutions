#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int	n, k, dp[55][55];
ll	a[55], rangeSums[55][55];

bool validate(int ind, ll mask, int shelves) {
	if (ind == n - 1 && shelves == 0) return 1;
	if (ind == n - 1 || shelves == 0) return 0;
	if (dp[ind + 1][shelves] != -1) return dp[ind + 1][shelves];

	for (int i = ind + 1; i < n; i++) {
		if (((mask & rangeSums[ind + 1][i]) == mask) && validate(i, mask, shelves - 1)) return (dp[ind + 1][shelves] = 1);
	}
	return (dp[ind + 1][shelves] = 0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			ll sum = 0;
			for (int l = i; l <= j; l++) sum += a[l];
			rangeSums[i][j] = rangeSums[j][i] = sum;
		}
	}

	ll ans = 0;
	for (int bit = 63; bit >= 0; bit--) {
		memset(dp, -1, sizeof dp);
		if (validate(-1, ans + (1LL << bit), k)) ans += (1LL << bit);
	}

	cout << ans << '\n';
}
