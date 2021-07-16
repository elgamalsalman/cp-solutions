#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int	minDiameter, tcNum, depth[30], maxDepth, tc, n, m;
vvi	adj;
bitset<30>	visited;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		minDiameter = 1e9;
		cin >> n >> m;
		adj.assign(n, vi());
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		for (int u1 = 0; u1 < n; u1++) {
			for (int i = -1; i < (int) adj[u1].size(); i++) {
				int u2;
				if (i == -1) u2 = u1;
				else u2 = adj[u1][i];

				visited.reset();
				maxDepth = 0;
				queue<int> q;
				q.push(u1); q.push(u2);
				visited[u1] = visited[u2] = 1;
				depth[u1] = depth[u2] = 0;
				while (!q.empty()) {
					int u = q.front(); q.pop();
					for (int v : adj[u]) {
						if (visited[v]) continue;
						visited[v] = 1;
						q.push(v);
						depth[v] = depth[u] + 1;
						maxDepth = max(maxDepth, depth[v]);
					}
				}
				maxDepth *= 2;
				if (i != -1) maxDepth++;
				minDiameter = min(minDiameter, maxDepth);
			}
		}

		cout << "Case #" << ++tcNum << ":\n" << minDiameter << "\n\n";
	}
}
