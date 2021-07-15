#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int	p[5050], maxDepth, N;
vi	furthestVs;
set<int>	bestRoots, worstRoots;
vvi	adj;
bitset<5050>	visited;

void dfs(int u, int depth) {
	if (depth > maxDepth) {
		maxDepth = depth;
		furthestVs.clear();
	}
	if (depth == maxDepth) furthestVs.push_back(u);
	visited[u] = 1;
	for (int v : adj[u]) {
		if (!visited[v]) {
			p[v] = u;
			dfs(v, depth + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> N) {
		worstRoots.clear();
		bestRoots.clear();
		adj.assign(N + 20, vi());
		for (int i = 0; i < N; i++) {
			int adjCount;;
			cin >> adjCount;
			for (int j = 0; j < adjCount; j++) {
				int v;
				cin >> v; v--;
				adj[i].push_back(v);
			}
		}

		maxDepth = 0;
		visited.reset();
		furthestVs.clear();
		dfs(0, 0);
		for (int u : furthestVs) worstRoots.insert(u);

		maxDepth = 0;
		visited.reset();
		int newSource = furthestVs[0];
		furthestVs.clear();
		memset(p, 0, sizeof p);
		dfs(newSource, 0);
		for (int u : furthestVs) worstRoots.insert(u);
		
		int currV = furthestVs[0];
		for (int i = 0; i < maxDepth / 2; i++) {
			currV = p[currV];
		}
		bestRoots.insert(currV);
		if (maxDepth % 2) bestRoots.insert(p[currV]);

		cout << "Best Roots  :";
		for (int u : bestRoots) cout << ' ' << u + 1;
		cout << '\n';

		cout << "Worst Roots :";
		for (int u : worstRoots) cout << ' ' << u + 1;
		cout << '\n';
	}
}
