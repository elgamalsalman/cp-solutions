#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define x first
#define y second
#define val first
#define pre second

typedef pair<int, int> ii;
typedef pair<double, int> di;
typedef vector<int> vi;

int	tc, n;
double	minDis, edges[10][10];
di	dp[2050][10];
ii	c[10];
vi	finalOrder;

di getMinDis (int bitmask, int lastC) {
	if (__builtin_popcount(bitmask) == 1) return {0, 0};
	
	di &currDpCell = dp[bitmask][lastC];
	if (currDpCell.val != 0) return currDpCell;

	currDpCell.val = 1e9;
	int	subBitmask = bitmask & ~(1 << lastC);
	double	minSubDis;
	for (int j = 0; j < n; j++) {
		if (!(subBitmask & (1 << j))) continue;
		minSubDis = getMinDis(subBitmask, j).val + edges[j][lastC];
		if (minSubDis < currDpCell.val) {
			currDpCell.val = minSubDis;
			currDpCell.pre = j;
		}
	}

	return currDpCell;
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n, n) {
		for (int i = 0; i < n; i++) {
			cin >> c[i].x >> c[i].y;
		}

		memset(edges, 0, sizeof edges);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				edges[i][j] = edges[j][i] = hypot(c[i].x - c[j].x, c[i].y - c[j].y) + 16;
			}
		}

		memset(dp, 0, sizeof dp);
		di ans = getMinDis((1 << (n + 1)) - 1, n);
		minDis = ans.val;

		finalOrder.clear();
		finalOrder.push_back(ans.pre);
		int dummyBitmask = (1 << n) - 1;
		for (int i = 0; i < n - 1; i++) {
			int preInd = finalOrder.back();
			finalOrder.push_back(dp[dummyBitmask][preInd].pre);
			dummyBitmask &= ~(1 << preInd);
		}

		cout << "**********************************************************\nNetwork #" << ++tc << '\n';

		for (int i = 1; i < n; i++) {
			cout << "Cable requirement to connect (" << c[finalOrder[i - 1]].x << ',' << c[finalOrder[i - 1]].y << ") to (" << c[finalOrder[i]].x << ',' << c[finalOrder[i]].y << ") is " << fixed << setprecision(2) << edges[finalOrder[i - 1]][finalOrder[i]] << " feet.\n";
		}

		cout << "Number of feet of cable required is " << fixed << setprecision(2) << minDis << ".\n";
	}
}
