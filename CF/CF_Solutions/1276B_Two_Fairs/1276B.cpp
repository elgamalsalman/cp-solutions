#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int	tc, n, m, a, b;
vvi	adj;
bitset<500050>	reachability[10];

void dfs(int u, int removedV, int reachabilityInd) {
	reachability[reachabilityInd][u] = 1;
	for (int v : adj[u]) {
		if (v == removedV) continue;
		if (reachability[reachabilityInd][v] == 0) {
			dfs(v, removedV, reachabilityInd);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> n >> m >> a >> b;
		adj.assign(n + 20, vi());
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		for (int i = 0; i < 4; i++) reachability[i].reset();
		dfs(a, -1, 0);
		dfs(b, -1, 1);

		dfs(a, b, 2);
		dfs(b, a, 3);

		long long bSide = 0, aSide = 0;
		for (int i = 1; i <= n; i++) {
			if (i == a || i == b) continue;
			if (reachability[0][i] && !reachability[3][i]) aSide++;
			if (reachability[1][i] && !reachability[2][i]) bSide++;
		}

		if (!reachability[0][b]) cout << "0\n";
		else cout << aSide * bSide << '\n';
	}
}
