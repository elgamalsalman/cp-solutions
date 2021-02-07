#include<bits/stdc++.h>

using namespace std;

int	tc, dp[220][22][12], nums[220], N, Q, D, M, numGroups;

int numWays(int index, int sumModD, int numUsedNums) {
	if (numUsedNums == M && !sumModD) return 1;
	if (numUsedNums == M || index == N) return 0;
	int &currDpCell = dp[index][sumModD][numUsedNums];
	if (currDpCell != -1) return currDpCell;
	currDpCell = numWays(index + 1, sumModD, numUsedNums);

	int newSum = (sumModD + nums[index]) % D;
	if (newSum < 0) newSum = D + newSum;
	currDpCell += numWays(index + 1, newSum, numUsedNums + 1);
	
	return currDpCell;
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> N >> Q && N && Q) {
		cout << "SET " << ++tc << ":\n";
		
		for (int i = 0; i < N; i++) cin >> nums[i];
		for (int i = 0; i < Q; i++) {
			memset(dp, -1, sizeof dp);
			numGroups = 0;
			cin >> D >> M;

			cout << "QUERY " << i + 1 << ": " << numWays(0, 0, 0) << '\n';
		}
	}
}
