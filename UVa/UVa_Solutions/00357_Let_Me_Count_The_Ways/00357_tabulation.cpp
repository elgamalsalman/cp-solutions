#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll	j, cents, dp[30100][5], coins[] = {1, 5, 10, 25, 50};

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	dp[0][0] = 1;
	for (int i = 0; i <= 30000; i++) {
		for (int coinInd = 0; coinInd < 5; coinInd++) {
			if (dp[i][coinInd] == 0) continue;
			if (coinInd < 4) dp[i][coinInd + 1] += dp[i][coinInd];
			dp[i + coins[coinInd]][coinInd] += dp[i][coinInd];
		}
	}

	while (cin >> cents) {
		ll ans = dp[cents][4];
		if (ans == 1) cout << "There is only 1 way";
		else cout << "There are " << ans << " ways";
		cout << " to produce " << cents << " cents change.\n";
	}
}
