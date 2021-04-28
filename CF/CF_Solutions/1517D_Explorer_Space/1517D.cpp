#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll	adj[505][505][4], di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0}, n, m, k, tmp, dp[25][505][505];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	memset(adj, -1, sizeof adj);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			cin >> tmp;
			adj[i][j][0] = adj[i][j + 1][2] = tmp;
		}
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tmp;
			adj[i][j][1] = adj[i + 1][j][3] = tmp;
		}
	}

	memset(dp, -1, sizeof dp);
	memset(dp[0], 0, sizeof dp[0]);
	for (int steps = 0; steps < k / 2; steps++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (dp[steps][i][j] == -1) continue;
				for (int dir = 0; dir < 4; dir++) {
					if (adj[i][j][dir] == -1) continue;
					ll &newCell = dp[steps + 1][i + di[dir]][j + dj[dir]];
					ll &currCell = dp[steps][i][j];
					if (newCell == -1 || newCell > currCell + adj[i][j][dir]) newCell = currCell + adj[i][j][dir];
				}
			}
		}
	}

	if (k % 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (j) cout << ' ';
				cout << -1;
			}
			cout << '\n';
		}
	} else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (j) cout << ' ';
				cout << (dp[k / 2][i][j] == -1 ? -1 : 2 * dp[k / 2][i][j]);
			}
			cout << '\n';
		}
	}
}
