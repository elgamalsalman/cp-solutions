#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define sideA first
#define sideB second

typedef pair<int, int> ii;

int	ans, dp[350][350], tc, m, S;
ii	coins[50];

int numCoins (int a, int b) {
	if (hypot(a, b) > S) return 500;
	if (hypot(a, b) == S) return 0;
	
	int &currDpCell = dp[a][b];
	if (currDpCell != 1000) return currDpCell;

	for (int i = 0; i < m; i++) {
		currDpCell = min(currDpCell, numCoins(a + coins[i].sideA, b + coins[i].sideB) + 1);
	}
	return currDpCell;
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> m >> S;
		for (int i = 0; i < m; i++) {
			cin >> coins[i].sideA >> coins[i].sideB;
			if (!coins[i].sideA && !coins[i].sideB) {
				i--; m--;
			}
		}

		for (int i = 0; i < 350; i++) {
			fill(dp[i], dp[i] + 350, 1000);
		}
		
		ans = numCoins(0, 0);
		if (ans >= 350) cout << "not possible\n";
		else cout << ans << '\n';
	}
}
