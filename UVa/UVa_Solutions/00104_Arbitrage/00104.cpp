#include <bits/stdc++.h>

using namespace std;

int	n, pred[22][22][22];
double	adj[22][22][22];

void printPath(int i, int j, int s) {
	if (s == 1) return;
	printPath(i, pred[s][i][j], s - 1);
	cout << pred[s][i][j] + 1 << ' ';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> n) {
		memset(adj, 0, sizeof adj);
		memset(pred, -1, sizeof pred);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					adj[1][i][j] = 1.0;
					pred[1][i][j] = i;
				} else {
					cin >> adj[1][i][j];
					pred[1][i][j] = i;
				}
			}
		}

		for (int s = 2; s <= n; s++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					for (int k = 0; k < n; k++) {
						double newVal = adj[s - 1][i][j] * adj[1][j][k];
						if (adj[s][i][k] < newVal) {
							adj[s][i][k] = newVal;
							pred[s][i][k] = j;
						}
					}
				}
			}
		}

		bool done = 0;
		for (int s = 2; s <= n && !done; s++) {
			for (int i = 0; i < n && !done; i++) {
				if (adj[s][i][i] >= 1.01) {
					cout << i + 1 << ' ';
					printPath(i, i, s);
					cout << i + 1 << '\n';
					done = 1;
				}
			}
		}

		if (!done) cout << "no arbitrage sequence exists\n";
	}
}
