#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define price first
#define favour second

typedef pair<int, int> ii;

int	m, n, dp[11000][105];
ii	dresses[105];

int maxFavour (int i, int usedMoney) {
	if (i >= n) {
		if (usedMoney <= m || (usedMoney > 2000 && usedMoney <= m + 200)) return 0;
		else return -1000;
	}
	if (usedMoney > m + 200) return -1000;

	int &currDpCell = dp[usedMoney][i];
	if (currDpCell != -1) return currDpCell;
	
	return currDpCell = max(maxFavour(i + 1, usedMoney + dresses[i].price) + dresses[i].favour, maxFavour(i + 1, usedMoney));
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> m >> n) {
		memset(dp, -1, sizeof dp);
		for (int i = 0; i < n; i++) {
			cin >> dresses[i].price >> dresses[i].favour;
		}

		cout << maxFavour(0, 0) << '\n';
	}
}
