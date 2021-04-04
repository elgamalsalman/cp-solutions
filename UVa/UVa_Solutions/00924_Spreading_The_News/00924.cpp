#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int	dis[2550], days[2550], q, T, N, E;
vvi	adj;

void bfs (int s) {
	queue<int> q;
	q.push(s);

	memset(dis, -1, sizeof dis);
	memset(days, 0, sizeof days);
	dis[s] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : adj[u]) {
			if (dis[v] == -1) {
				dis[v] = dis[u] + 1;
				days[dis[v]]++;
				q.push(v);
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> E;

	adj.assign(E, vi());
	for (int i = 0; i < E; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			int v; cin >> v;
			adj[i].push_back(v);
		}
	}

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> q;
		bfs(q);
		auto it = max_element(days, days + 2550);
		if (it == days) cout << "0\n";
		else cout << *it << ' ' << distance(days, it) << '\n';
	}
}
