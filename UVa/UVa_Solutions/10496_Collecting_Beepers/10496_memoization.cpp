#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define x first
#define y second

typedef pair<int, int> ii;

int	dp[2050][12], beepersNum, tc, distances[12][12];
ii	dims, beepers[12];

int getMinDis (int bitmask, int lastBeeper) {
	if (__builtin_popcount(bitmask) == 1) return distances[0][lastBeeper];

	int &currDpCell = dp[bitmask][lastBeeper];
	if (currDpCell != 1e5) return currDpCell;

	int subBitmask = bitmask & ~(1 << lastBeeper);
	for (int i = 0; i < beepersNum; i++) {
		if (!(subBitmask & (1 << i))) continue;
		currDpCell = min(currDpCell, getMinDis(subBitmask, i) + distances[i][lastBeeper]);
	}

	return currDpCell;
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> dims.x >> dims.y;

		memset(beepers, 0, sizeof beepers);
		cin >> beepers[0].x >> beepers[0].y;
		cin >> beepersNum; beepersNum++;
		for (int i = 1; i < beepersNum; i++) {
			cin >> beepers[i].x >> beepers[i].y;
		}
		
		memset(distances, 0, sizeof distances);
		for (int j = 0; j < beepersNum; j++) {
			for (int i = 0; i < beepersNum; i++) {
				distances[i][j] = distances[j][i] = abs(beepers[i].x - beepers[j].x) + abs(beepers[i].y - beepers[j].y);
			}
		}

		for (int i = 0; i < 2050; i++) {
			fill(dp[i], dp[i] + 12, 1e5);
		}
		cout << "The shortest path has length " << getMinDis((1 << beepersNum) - 1, 0) << '\n';
	}
}
