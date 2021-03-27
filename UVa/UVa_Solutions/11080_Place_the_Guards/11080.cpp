#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int	minGuards, ones, zeros, colour[250], tc, v, e, a, b;
vvi	adj;
bool	isBipartite;

void dfs (int u) {
	for (int i = 0; i < (int) adj[u].size(); i++) {
		int v = adj[u][i];
		if (colour[v] == -1) {
			colour[v] = !colour[u];
			if (colour[v]) ones++; else zeros++;
			dfs(v);
		} else if (colour[v] == colour[u]) isBipartite = 0;
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		isBipartite = 1; minGuards = 0;
		memset(colour, -1, sizeof colour);

		cin >> v >> e;
		adj.assign(v + 20, vi());
		for (int i = 0; i < e; i++) {
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		for (int i = 0; i < v; i++) {
			if (colour[i] == -1) {
				zeros = 1; ones = 0;
				colour[i] = 0;
				dfs(i);

				minGuards += max(1, min(ones, zeros));
			}
		}

		cout << (isBipartite ? minGuards : -1) << '\n';
	}
}
