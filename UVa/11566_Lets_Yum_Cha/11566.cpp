#include<bits/stdc++.h>

using namespace std;

int	availableMoney, dp[2][2500][23], p[201], f[201], N, x, K, T;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> N >> x >> T >> K && (N || x || T || K)) { 
		for (int i = 0; i < 2 * K; i+=2) {
			cin >> p[i];
			p[i + 1] = p[i];
			int currTotalFavour = 0;
			for (int j = 0; j <= N; j++) {
				int tmp; cin >> tmp;
				currTotalFavour += tmp;
			}
			f[i + 1] = f[i] = currTotalFavour;
		}

		availableMoney = x * (N + 1);

		memset(dp, -1, sizeof dp);

		// Base Cases
		dp[0][0][0] = 0;
		if (p[0] <= availableMoney) dp[0][p[0]][1] = f[0];

		// propagate
		bool currDpRow = 0;
		for (int i = 0; i < 2 * K - 1; i++) {
			for (int usedMoney = 0; usedMoney <= availableMoney; usedMoney++) {
				for (int usedDishes = 0; usedDishes <= 2 * (N + 1); usedDishes++) {
					if (dp[currDpRow][usedMoney][usedDishes] == -1) continue;
					if (dp[!currDpRow][usedMoney][usedDishes] < dp[currDpRow][usedMoney][usedDishes]) dp[!currDpRow][usedMoney][usedDishes] = dp[currDpRow][usedMoney][usedDishes];

					int nextUsedMoney = usedMoney + p[i + 1];
					if (usedDishes < 2 * (N + 1) && nextUsedMoney <= availableMoney) {
						if (dp[!currDpRow][nextUsedMoney][usedDishes + 1] < dp[currDpRow][usedMoney][usedDishes] + f[i + 1]) {
								dp[!currDpRow][nextUsedMoney][usedDishes + 1] = dp[currDpRow][usedMoney][usedDishes] + f[i + 1];
						} 
					}
				}
			}
			currDpRow = !currDpRow;
		}

		int mxFavour = 0;
		for (int usedMoney = 0; ceil((usedMoney + (N + 1) * T) * 1.1) <= availableMoney; usedMoney++) {
			for (int usedDishes = 0; usedDishes <= 2 * (N + 1); usedDishes++) {
				mxFavour = max(mxFavour, dp[currDpRow][usedMoney][usedDishes]);
			}
		}

		cout << fixed << setprecision(2) << mxFavour / (N + 1.0) << '\n';
	}
}
