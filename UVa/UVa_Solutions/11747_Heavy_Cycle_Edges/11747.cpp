#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define ww first
#define vv second

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int	n, m;
vvii	adj;
set<int>	ans;
bitset<1050>	taken, visited;
priority_queue<ii>	edges;

void take (int u) {
	taken[u] = 1;

	for (int i = 0; i < (int) adj[u].size(); i++) {
		ii edge = adj[u][i];
		if (!taken[edge.vv]) edges.push({-edge.ww, edge.vv});
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n >> m, n || m) {
		ans.clear();
		adj.assign(n, vii());
		taken.reset();
		visited.reset();

		int	u, v, w;
		for (int i = 0; i < m; i++) {
			cin >> u >> v >> w;
			adj[u].push_back({w, v});
			adj[v].push_back({w, u});
		}

		for (int i = 0; i < n; i++) {
			if (visited[i]) continue;
			take(i);
			while (!edges.empty()) {
				ii edge = edges.top(); edges.pop();
				if (!taken[edge.vv]) take(edge.vv);
				else ans.insert(-edge.ww);
			}
		}

		if (ans.empty()) cout << "forest";

		bool first = 1;
		for (auto it = ans.begin(); it != ans.end(); it++) {
			if (first) first = 0;
			else cout << ' ';
			cout << *it;
		}
		cout << '\n';
	}
}
