#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int	cc, n, m, q;
bitset<400050>	visited;
vvi	adj;

void dfs(int u) {
	visited[u] = 1;
	for (int v : adj[u]) {
		if (visited[v]) continue;
		dfs(v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> q;
	adj.assign(n + m + 20, vi());
	for (int i = 0; i < q; i++) {
		int r, c;
		cin >> r >> c; r--; c--;
		adj[r].push_back(c + n);
		adj[c + n].push_back(r);
	}

	for (int i = 0; i < n + m; i++) {
		if (visited[i]) continue;
		dfs(i); 
		cc++;
	}

	cout << cc - 1 << '\n';
}
