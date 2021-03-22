#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int	a, b, mnRebuilds, mxRebuilds, n, m, k, path[200050], sssp[200050];
vvi	parents, adj;

void bfs (int dest) {
	queue<int> q; q.push(dest);

	memset(sssp, -1, sizeof sssp);
	sssp[dest] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < (int) adj[u].size(); i++) {
			int v = adj[u][i];
			if (sssp[v] == -1) {
				q.push(v);
				sssp[v] = sssp[u] + 1;
				parents[v].push_back(u);
			} else if (sssp[v] == sssp[u] + 1) {
				parents[v].push_back(u);
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	parents.resize(n + 50); adj.resize(n + 50);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[b].push_back(a);
	}

	cin >> k;
	for (int j = 0; j < k; j++) cin >> path[j];
	bfs(path[k - 1]);

	for (int i = 0; i < k - 1; i++) {
		bool present = 0;
		for (int j = 0; j < (int) parents[path[i]].size(); j++) {
			if (parents[path[i]][j] == path[i + 1]) {
				present = 1; break;
			}
		}

		if (!present) {
			mnRebuilds++; mxRebuilds++;
		} else if (parents[path[i]].size() > 1) mxRebuilds++;
	}

	cout << mnRebuilds << ' ' << mxRebuilds << '\n';
}
