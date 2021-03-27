#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int	colour[250], a, b, l, n;
vvi	adj;
bool	isBipartite = 1;

void dfs (int u) {
	for (int i = 0; i < (int) adj[u].size(); i++) {
		int v = adj[u][i];
		if (colour[v] == -1) {
			colour[v] = !colour[u];
			dfs(v);
		} else if (colour[u] == colour[v]) isBipartite = 0;
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n, n) {
		isBipartite = 1;
		memset(colour, -1, sizeof colour);
		adj.assign(n + 20, vi());

		cin >> l;
		for (int i = 0; i < l; i++) {
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		colour[0] = 0;
		dfs(0);

		cout << (isBipartite ? "BICOLORABLE.\n" : "NOT BICOLORABLE.\n");
	}
}
