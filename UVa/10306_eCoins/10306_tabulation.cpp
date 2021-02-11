#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define sideA first
#define sideB second

typedef pair<int, int> ii;

int	ans, dp[350][350], tc, m, S;
ii	coins[50];

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> m >> S;
		for (int i = 0; i < m; i++) {
			cin >> coins[i].sideA >> coins[i].sideB;
		}

		for (int i = 0; i < 350; i++) {
			fill(dp[i], dp[i] + 350, 1000);
		}

		ans = 1000;
		// Base Cases
		dp[0][0] = 0;
		// Propagate
		for (int a = 0; a <= S; a++) {
			for (int b = 0; b <= S; b++) {
				if (dp[a][b] == 1000) continue;
				if (hypot(a, b) == S) ans = min(ans, dp[a][b]);
				for (int i = 0; i < m; i++) {
					int newA = a + coins[i].sideA;
					int newB = b + coins[i].sideB;
					if (newA > S || newB > S) continue;
					dp[newA][newB] = min(dp[newA][newB], dp[a][b] + 1);
				}
			}
		}
		if (ans == 1000) cout << "not possible\n";
		else cout << ans << '\n';
	}
}
