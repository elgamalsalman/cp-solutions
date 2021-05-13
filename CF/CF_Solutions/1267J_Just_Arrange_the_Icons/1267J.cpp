#include <bits/stdc++.h>

using namespace std;

int	minCat, cNum, s, ans, n, c[2000050], tc;
vector<int>	categories;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		memset(c, 0, sizeof c);
		categories.clear();
		ans = 1e9;
		cNum = 0;

		cin >> n;
		for (int i = 0; i < n; i++) {
			int category;
			cin >> category;
			c[category]++;
			if (cNum < category) cNum = category;
		}

		minCat = 1e9;
		for (int i = 1; i <= cNum; i++) if (c[i]) {
			if (minCat > c[i]) minCat = c[i];
			categories.push_back(c[i]);
		}	

		for (s = 1; s <= minCat + 1; s++) {
			int m = 0;
			for (int category : categories) {
				int screens = ceil(category / (double) s);
				int unfilledScreens = screens * s - category;
				if (unfilledScreens > screens) m = 1e7;
				else m += screens;
			}

			if (ans > m) ans = m;
		}

		cout << ans << '\n';
	}
}
