#include<bits/stdc++.h>

using namespace std;

int	minNumCoins, minMoneyPaid, p, coins[150], tc, dp[105][10050], n;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> p >> n;
		for (int i = 0; i < n; i++) {
			cin >> coins[i];
		}

		for (int i = 0; i < 105; i++) {
			fill(dp[i], dp[i] + 10050, 11000);
		}
		minNumCoins = minMoneyPaid = 20000;

		// Base Cases
		dp[0][0] = 0;

		// Propagate
		for (int i = 0; i < n; i++) {
			for (int money = 0; money < p; money++) {
				if (dp[i][money] == 11000) continue;
				for (int j = (!i && !money ? i : i + 1); j < n; j++) {
					int newMoney = money + coins[j];
					if (newMoney < p) {
						dp[j][newMoney] = min(dp[j][newMoney], dp[i][money] + 1);
					}
					if (newMoney >= p){
						if (newMoney < minMoneyPaid) {
							minMoneyPaid = newMoney;
							minNumCoins = dp[i][money] + 1;
						} else if (newMoney == minMoneyPaid && dp[i][money] + 1 < minNumCoins) {
							minNumCoins = dp[i][money] + 1;
						} 
					}
				}
			}
		}

		cout << minMoneyPaid << ' ' << minNumCoins << '\n';
	}
}
