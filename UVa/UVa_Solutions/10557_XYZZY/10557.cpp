#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

ll	doors, dis[105], n, energies[105], connected[105]; 
vvi	adj;
bool	ans;
bitset<105>	visited;

bool dfs (int u) {
	if (u == n) return 1;
	if (visited[u]) return 0;
	
	visited[u] = 1;
	for (int v : adj[u]) {
		if (dfs(v)) return 1;
	}

	return 0;
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while (cin >> n, n != -1) {
		adj.assign(n + 20, vi());

		for (int i = 1; i <= n; i++) {
			cin >> energies[i] >> doors;
			for (int j = 0; j < doors; j++) {
				int v; cin >> v;
				adj[i].push_back(v);
			}
		}

		ans = 0;
		fill(dis, dis + 105, -1e18);
		dis[1] = 100;
		for (int i = 0; i < n; i++) {
			for (int u = 1; u <= n; u++) {
				if (dis[u] == -1e18) continue;
				for (int v : adj[u]) {
					if (dis[v] < dis[u] + energies[v] && dis[u] + energies[v] > 0) {
						dis[v] = dis[u] + energies[v];
						if (i == n - 1) {
							visited.reset();
							if (dfs(u)) ans = 1;
						}
					}
				}
			}
		}

		if (ans || dis[n] > 0) cout << "winnable\n";
		else cout << "hopeless\n";
	}
}
