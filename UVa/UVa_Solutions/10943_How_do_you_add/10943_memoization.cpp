#include<bits/stdc++.h>

using namespace std;

int	N, K, dp[105][105];

int countWays (int numDigits, int sum) {
	if (!numDigits) {
		if (sum) return 0;
		else return 1;
	}

	int &currCell = dp[numDigits][sum];
	if (currCell != -1) return currCell;

	currCell = 0;
	for (int i = 0; i <= sum; i++) {
		currCell += countWays(numDigits - 1, sum - i);
		currCell %= 1000000;
	}

	return currCell;
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> N >> K && N && K) {
		memset(dp, -1, sizeof dp);
		cout << countWays(K, N) << '\n';
	}
}
