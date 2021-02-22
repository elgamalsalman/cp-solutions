#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define x first
#define y second

typedef pair<int, int> ii;

int	tcNum,  ansPerm[10], perm[10], n;
double	edges[10][10], dis, minDis;
ii	c[10];

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n, n) {
		for (int i = 0; i < n; i++) {
			cin >> c[i].x >> c[i].y;
			perm[i] = i;
		}

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				edges[i][j] = edges[j][i] = hypot(c[i].x - c[j].x, c[i].y - c[j].y) + 16;
			}
		}

		minDis = 1e8;
		do {
			dis = 0;
			for (int i = 1; i < n; i++) {
				dis += edges[perm[i]][perm[i - 1]];
			}
			if (dis < minDis) {
				minDis = dis;
				copy(perm, perm + n, ansPerm);
			}
		} while (next_permutation(perm, perm + n));

		cout << "**********************************************************\nNetwork #" << ++tcNum << '\n';
		for (int i = 1; i < n; i++) {
			cout << "Cable requirement to connect (" << c[ansPerm[i - 1]].x << ',' << c[ansPerm[i - 1]].y << ") to (" << c[ansPerm[i]].x << ',' << c[ansPerm[i]].y << ") is " << fixed << setprecision(2) << edges[ansPerm[i]][ansPerm[i - 1]] << " feet.\n";
		}
		cout << "Number of feet of cable required is " << fixed << setprecision(2) << minDis << ".\n";
	}
}
