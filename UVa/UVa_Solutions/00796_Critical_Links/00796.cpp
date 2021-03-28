#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int	dfsParent[505], dfsCounter, dfsNum[505], dfsLow[505], k, n;
vvi	adj;
vii	articulationEdges;

void findArticulations (int u) {
	dfsNum[u] = dfsLow[u] = ++dfsCounter;

	for (int i = 0; i < (int) adj[u].size(); i++) {
		int v = adj[u][i];

		if (dfsNum[v] == -1) {
			dfsParent[v] = u;

			findArticulations(v);

			dfsLow[u] = min(dfsLow[u], dfsLow[v]);
			if (dfsLow[v] > dfsNum[u]) articulationEdges.push_back({min(u, v), max(u, v)});
		} else if (v != dfsParent[u]) dfsLow[u] = min(dfsLow[u], dfsNum[v]);
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n) {
		dfsCounter = 0;
		adj.assign(n, vi());
		memset(dfsNum, -1, sizeof dfsNum);
		articulationEdges.clear();

		for (int i = 0; i < n; i++) {
			int u, v;

			cin >> u; cin.ignore(2);
			cin >> k; cin.ignore();

			for (int j = 0; j < k; j++) {
				cin >> v;
				adj[u].push_back(v);
			}
		}

		for (int i = 0; i < n; i++)
			if (dfsNum[i] == -1)
				findArticulations(i);

		sort(articulationEdges.begin(), articulationEdges.end());
		cout << articulationEdges.size() << " critical links\n";
		for (int i = 0; i < (int) articulationEdges.size(); i++) {
			cout << articulationEdges[i].first << " - " << articulationEdges[i].second << '\n';
		}

		cout << '\n';
	}
}
