#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll	n, s[2050], dp[2050][2050];

ll findD(int l, int r) {
	if (l < 0 || r >= n) return 1e18;
	if (l == r) return 0;

	ll &currCell = dp[l][r];
	if (currCell != -1) return currCell;

	return currCell = s[r] - s[l] + min(findD(l + 1, r), findD(l, r - 1));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	sort(s, s + n);

	memset(dp, -1, sizeof dp);
	cout << findD(0, n - 1) << '\n';
}
