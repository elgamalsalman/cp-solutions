#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define price first
#define favour second

typedef pair<int, int> ii;

int	maxFavour, dp[105][11000], m, n;
ii	dresses[105];

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> m >> n) {
		maxFavour = 0;
		for (int i = 0; i < n; i++) {
			cin >> dresses[i].price >> dresses[i].favour;
		}

		memset(dp, -1, sizeof dp);

		// Base Cases
		dp[0][0] = 0;
		if (n) dp[0][dresses[0].price] = dresses[0].favour;

		// propagate
		bool currDpRow = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int usedMoney = 0; usedMoney <= m + 200; usedMoney++) {
				if (dp[currDpRow][usedMoney] == -1) continue;
				dp[!currDpRow][usedMoney] = max(dp[!currDpRow][usedMoney], dp[currDpRow][usedMoney]);
				int nextUsedMoney = usedMoney + dresses[i + 1].price;
				if (nextUsedMoney <= m + 200) dp[!currDpRow][nextUsedMoney] = max(dp[!currDpRow][nextUsedMoney], dp[currDpRow][usedMoney] + dresses[i + 1].favour);
			}
			currDpRow = !currDpRow;
		}

		if (n) for (int usedMoney = 0; usedMoney <= m + 200; usedMoney++) {
			if (usedMoney <= m || (usedMoney > 2000 && usedMoney <= m + 200))
				maxFavour = max(maxFavour, dp[currDpRow][usedMoney]);
		}

		cout << maxFavour << '\n';
	}
}
