#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int	colours[350], V, a, b;
vvi	adj;
bool	isBipartite;

void dfs (int u) {
	for (int i = 0; i < (int) adj[u].size(); i++) {
		int v = adj[u][i];

		if (colours[v] == -1) {
			colours[v] = !colours[u];
			dfs(v);
		} else if (colours[u] == colours[v]) isBipartite = 0;
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> V, V) {
		isBipartite = 1;
		adj.assign(V + 20, vi());
		memset(colours, -1, sizeof colours);

		while (cin >> a >> b, a || b) {
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		for (int i = 1; i <= V; i++) {
			if (colours[i] == -1) {
				colours[i] = 0;
				dfs(i);
			}
		}

		cout << (isBipartite ? "YES" : "NO") << '\n';
	}
}
