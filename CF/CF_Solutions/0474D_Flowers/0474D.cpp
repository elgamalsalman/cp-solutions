#include<bits/stdc++.h>

using namespace std;

#define MODVAL 1000000007

typedef long long ll;

ll	dp[100050], t, k, a, b;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t >> k;
	memset(dp, 0, sizeof dp);
	dp[0] = 1;
	for (int i = 0; i < 1e5; i++) {
		dp[i + 1] = (dp[i + 1] + dp[i]) % MODVAL;
		if (i + k <= 1e5) dp[i + k] = (dp[i + k] + dp[i]) % MODVAL;
	}

	partial_sum(dp, dp + 100005, dp);

	while (t--) {
		cin >> a >> b;
		cout << (dp[b] - dp[a - 1]) % MODVAL << '\n';
	}
}
