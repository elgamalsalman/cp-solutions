#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int	T, tIn[200050], tOut[200050], k, parent[200050], queryVs[200050], n, m;
vvi	adj;
bitset<200050>	visited;

void dfs(int u) {
	visited[u] = 1;
	tIn[u] = ++T;
	for (int v : adj[u]) if (visited[v] == 0) {
		parent[v] = u;
		dfs(v);
	}
	tOut[u] = T;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	adj.assign(n + 20, vi());
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	visited.reset();
	memset(parent, -1, sizeof parent);
	memset(tIn, 0, sizeof tIn);
	memset(tOut, 0, sizeof tOut);
	T = 0;
	dfs(1);

	while (m--) {
		cin >> k;
		int lowT = 0, highT = T;
		for (int i = 0; i < k; i++) {
			int v; cin >> v;
			if (v != 1) v = parent[v];
			if (lowT < tIn[v]) lowT = tIn[v];
			if (highT > tOut[v]) highT = tOut[v];
		}

		cout << (highT >= lowT ? "YES" : "NO") << '\n';
	}
}
