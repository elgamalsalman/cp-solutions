#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll	i, l, r, cNum, hNum, minNum, tc, h, c, t;
double	minDiff, tb;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> h >> c >> t;

		minDiff = h - t; minNum = 1;
		if (minDiff > abs((h + c) / 2.0 - t)) {
			minDiff = abs((h + c) / 2.0 - t);
			minNum = 2;
		}

		for (l = 0, r = 1e6, i = 0; i < 25; i++) {
			cNum = (l + r) / 2;
			hNum = cNum + 1;

			tb = (cNum * c + hNum * h) / (double)(cNum + hNum);
			if (minDiff > abs(t - tb)) {
				minDiff = abs(t - tb);
				minNum = cNum + hNum;
			}

			if (tb < t) r = cNum;
			else if (tb > t) l = cNum + 1;
			else break;
		}

		cout << minNum << '\n';
	}
}
