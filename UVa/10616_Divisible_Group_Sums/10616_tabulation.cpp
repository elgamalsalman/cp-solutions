#include<bits/stdc++.h>

using namespace std;

int	setNum, dp[2][22][12], nums[220], N, Q, D, M;

int mod (int newSum) {
	newSum = newSum % D;
	if (newSum < 0) newSum = D + newSum;
	return newSum;
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cerr.tie(0);

	while (cin >> N >> Q && N && Q) {
		cout << "SET " << ++setNum << ":\n";

		for (int i = 0; i < N; i++) cin >> nums[i];

		int queryNum = 0; 
		for (int j = 0; j < Q; j++) {
			memset(dp, 0, sizeof dp);
			cin >> D >> M;

			// Base Cases
			dp[0][0][0] = dp[0][mod(nums[0])][1] = 1;

			// Propagate through the table
			int currDpRow = 0;
			for (int currInd = 0; currInd < N - 1; currInd++) {
				for (int currSumModD = 0; currSumModD < D; currSumModD++) {
					for (int currNumUsedNums = 0; currNumUsedNums <= M; currNumUsedNums++) {

						if (!dp[currDpRow][currSumModD][currNumUsedNums]) continue;
						dp[!currDpRow][mod(currSumModD + nums[currInd + 1])][currNumUsedNums + 1] += dp[currDpRow][currSumModD][currNumUsedNums];
						dp[!currDpRow][currSumModD][currNumUsedNums] += dp[currDpRow][currSumModD][currNumUsedNums];
					}
				}
				memset(dp[currDpRow], 0, sizeof dp[currDpRow]);
				currDpRow = !currDpRow;
			}

			//cerr << "// dp :-\n";
			//for (int k = 0; k < N; k++) {
			//	for (int j = 0; j < D; j++) {
			//		for (int i = 0; i <= M; i++) {
			//			cerr << ", " << dp[k][j][i];
			//		}
			//		cerr << '\n';
			//	}
			//	cerr << '\n';
			//}

			cout << "QUERY " << ++queryNum << ": " <<  dp[currDpRow][0][M] << '\n';
		}
	}
}

/*
 * Base Cases:-
 * 	the element with index = 0, sumModD = 0, numUsedNums = 0.
 * 	the element with index = 0, sumModD = nums[0] % D, numUsedNums = 1.
 * 	should both be set to 1
 *
 * numWays(index, sumModD, numUsedNums) = numWays(index - 1, (sumModD - nums[index]) % D, numUsedNums - 1) + numWays(index - 1, sumModD, numUsedNums);
 *
 * numWays(index, sumModD, numUsedNums)
 * 	=> numWays(index + 1, (sumModD + nums[index + 1]) % D, numUsedNums + 1);
 * 	=> numWays(index + 1, sumModD, numUsedNums);
 */
