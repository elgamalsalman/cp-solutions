#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int	n, k, m;
ll	dp[55][55];

ll countCodes (int numBars, int numUnits) {
	if (numUnits < numBars || numBars < 0 || numUnits < 0) return 0;
	if (!numBars && !numUnits) return 1;

	ll &currCell = dp[numBars][numUnits];
	if (currCell != -1) return currCell;

	currCell = 0;
	for (int i = 1; i <= m; i++) {
		currCell += countCodes(numBars - 1, numUnits - i);
	}
	return currCell;

}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n >> k >> m) {
		memset(dp, -1, sizeof dp);
		cout << countCodes(k, n) << '\n';
	}
}
