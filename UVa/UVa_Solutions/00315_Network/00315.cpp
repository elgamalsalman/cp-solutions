#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int	articulationsNum, dfsParents[105], rootChildren, dfsLow[105], dfsCounter, dfsNum[105], N;
vvi	adj;
bitset<105>	articulations;

void findArticulations (int u) {
	//cerr << "// findArticulations(" << u << ")\n";
	dfsNum[u] = dfsLow[u] = ++dfsCounter;

	for (int i = 0; i < (int) adj[u].size(); i++) {
		int v = adj[u][i];
		if (dfsNum[v] == -1) {
			if (u == 1) rootChildren++;
			dfsParents[v] = u;

			findArticulations(v);

			if (dfsLow[v] >= dfsNum[u]) articulations[u] = 1;
			dfsLow[u] = min(dfsLow[u], dfsLow[v]);
		} else if (v != dfsParents[u]) {
			dfsLow[u] = min(dfsLow[u], dfsNum[v]);
		}

	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> N, N) {
		articulationsNum = rootChildren = 0;
		adj.assign(N + 20, vi());
		memset(dfsNum, -1, sizeof dfsNum);
		memset(dfsLow, -1, sizeof dfsLow);
		articulations.reset();

		int u, v;
		while (cin >> u, u) {
			while (cin.get() != '\n') {
				cin >> v;
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}

		findArticulations(1);
		articulations[1] = (rootChildren > 1);

		for (int i = 1; i <= N; i++) {
			if (articulations[i]) articulationsNum++;
		}

		cout << articulationsNum << '\n';
	}
}
