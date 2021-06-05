#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

int	tc, times[300050], n, m;
viii	robots;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		memset(times, -1, sizeof times);
		robots.clear();

		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int pos;
			cin >> pos;
			robots.push_back({{pos, 0}, i});
		}

		for (int i = 0; i < n; i++) {
			string letter;
			cin >> letter;
			if (letter == "R") robots[i].fi.se = 1;
			else robots[i].fi.se = -1;
		}
		
		sort(robots.begin(), robots.end());

		for (int j = 0; j < 2; j++) {
			stack<iii> s;
			for (int i = 0; i < n; i++) {
				if (abs(robots[i].fi.fi % 2) == j) continue;
				if (robots[i].fi.se == 1) {
					s.push(robots[i]);
				} else if (s.empty()) {
					s.push({{-robots[i].fi.fi, 1}, robots[i].se});
				} else {
					iii collidingRobot = s.top(); s.pop();
					int time = abs(collidingRobot.fi.fi - robots[i].fi.fi) / 2;
					times[collidingRobot.se] = times[robots[i].se] = time;
				}
			}

			while (s.size() > 1) {
				iii r1 = s.top(); s.pop();
				iii r2 = s.top(); s.pop();

				int time = (2*m - r1.fi.fi - r2.fi.fi) / 2;
				times[r1.se] = times[r2.se] = time;
			}

			if (!s.empty()) s.pop();
		}

		for (int i = 0; i < n; i++) {
			cout << times[i] << " \n"[i == n - 1];
		}
	}
}
