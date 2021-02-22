#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int	cents, coins[] = {1, 5, 10, 25, 50};
ll	dp[30100][5]; 

ll numWays(int cents, int lastCoinAllowed) {
	if (cents == 0) return 1;
	if (lastCoinAllowed == 0) return 1;
	if (cents < 0) return 0;

	ll &currDpCell = dp[cents][lastCoinAllowed];
	if (currDpCell != -1) return currDpCell;


	return (currDpCell = numWays(cents, lastCoinAllowed - 1) + numWays(cents - coins[lastCoinAllowed], lastCoinAllowed));
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	memset(dp, -1, sizeof dp);

	while (cin >> cents) {
		ll ans = numWays(cents, 4);
		if (ans == 1) cout << "There is only 1 way";
		else cout << "There are " << ans << " ways";
		cout << " to produce " << cents << " cents change.\n";
	}
}
