#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int	dfsCounter, dfsNum[10050], dfsLow[10050], dfsParent[10050], n, m;
vvi	adj;
ii	articulations[10050];

void findArticulations (int u) {
	dfsNum[u] = dfsLow[u] = ++dfsCounter;

	for (int i = 0; i < (int) adj[u].size(); i++) {
		int v = adj[u][i];

		if (dfsNum[v] == -1) {
			dfsParent[v] = u;

			findArticulations(v);
			dfsLow[u] = min(dfsLow[u], dfsLow[v]);

			if (dfsLow[v] >= dfsNum[u]) {
				articulations[u].first = u;
				articulations[u].second++;
			}
		} else if (dfsParent[u] != v)
			dfsLow[u] = min(dfsLow[u], dfsNum[v]);
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n >> m, n || m) {
		dfsCounter = 0;
		adj.assign(n + 20, vi());
		memset(dfsNum, -1, sizeof dfsNum);
		memset(articulations, 0, sizeof articulations);
		for (int i = 0; i < n; i++) articulations[i] = {i, !!i};

		int u, v;
		while (cin >> u >> v, u != -1) {
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		findArticulations(0);

		sort(articulations, articulations + n, [](ii ele1, ii ele2) {
				if (ele1.second != ele2.second) return ele1.second > ele2.second;
				else return ele1.first < ele2.first;
				});

		for (int i = 0; i < m; i++)
			cout << articulations[i].first << ' ' << articulations[i].second << '\n';
		cout << '\n';
	}
}
