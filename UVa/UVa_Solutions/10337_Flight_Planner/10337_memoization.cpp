#include<bits/stdc++.h>

using namespace std;

int	dp[10][1050], wind[10][1050], totalDis, tc;

int getMinFuel (int startAlt, int startDis) {
	if (startAlt < 0 || startAlt > 9) return 1e7;
	if (startDis == totalDis) {
		if (!startAlt) return 0;
		else return 1e7;
	}

	int &currCell = dp[startAlt][startDis];
	if (currCell != 1e6) return currCell;

	currCell = min(currCell, 60 - wind[startAlt][startDis] + getMinFuel(startAlt + 1, startDis + 1));
	currCell = min(currCell, 30 - wind[startAlt][startDis] + getMinFuel(startAlt, startDis + 1));
	currCell = min(currCell, 20 - wind[startAlt][startDis] + getMinFuel(startAlt - 1, startDis + 1));

	return currCell;
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> totalDis; totalDis /= 100;
		for (int i = 9; i >= 0; i--) {
			for (int j = 0; j < totalDis; j++) cin >> wind[i][j];
		}

		for (int i = 0; i < 10; i++) {
			fill(dp[i], dp[i] + 1050, 1e6);
		}
		cout << getMinFuel(0, 0) << "\n\n";
	}
}

// 59 21 21 19
