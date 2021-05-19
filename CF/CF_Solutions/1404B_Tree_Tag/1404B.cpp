#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int	farthestDis, farthestV, dis[100050], tc, n, a, b, da, db;
vvi	adj;
bitset<100050>	visited;

void dfs(int s, int d) {
	visited[s] = 1;
	for (int v : adj[s]) {
		if (!visited[v]) {
			visited[v] = 1;
			dis[v] = d + 1;
			if (d + 1 > farthestDis) {
				farthestV = v;
				farthestDis = d + 1;
			}
			dfs(v, d + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {

		cin >> n >> a >> b >> da >> db;
		adj.assign(n + 20, vi());

		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		visited.reset();
		farthestDis = dis[a] = 0;
		farthestV = a;
		dfs(a, 0);
		if (dis[b] <= da) {
			cout << "Alice\n";
			continue;
		}

		visited.reset();
		farthestDis = dis[farthestV] = 0;
		dfs(farthestV, 0);
		if (farthestDis + 1 <= da * 2 + 1) cout << "Alice\n";
		else if (db > 2 * da) cout << "Bob\n";
		else cout << "Alice\n";
	}
}
