#include<bits/stdc++.h>

using namespace std;

int	minRec = 5000, a, b, n, m, adj[4050][4050], degree[4050];

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a][b] = adj[b][a] = 1;
		degree[a]++; degree[b]++;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (!adj[i][j]) continue;
			for (int k = 0; k <= n; k++) {
				if (adj[i][k] && adj[j][k]) minRec = min(minRec, degree[i] + degree[j] + degree[k] - 6);
			}
		}
	}

	cout << (minRec == 5000 ? -1 : minRec) << '\n';
}
