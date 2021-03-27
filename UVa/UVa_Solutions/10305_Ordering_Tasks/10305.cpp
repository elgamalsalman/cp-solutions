#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int	dfsState[105], a, b, indegree[105], n, m;
vi	topo;
vvi	adj;

void topoSort (int u) {
	if (!dfsState[u]) return;
	dfsState[u] = 0;

	for (int i = 0; i < (int) adj[u].size(); i++) {
		topoSort(adj[u][i]);
	}
	topo.push_back(u);
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n >> m, n || m) {
		memset(dfsState, -1, sizeof dfsState);
		memset(indegree, 0, sizeof indegree);
		adj.assign(n + 20, vi()); topo.clear();

		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			adj[a].push_back(b);
			indegree[b]++;
		}

		for (int i = 1; i <= n; i++) {
			if (!indegree[i]) topoSort(i);
		}

		for (int i = n - 1; i >= 0; i--) {
			cout << topo[i] << (i ? " " : "\n");
		}
	}
}
