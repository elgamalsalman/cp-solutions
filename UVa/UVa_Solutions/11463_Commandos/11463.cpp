#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int	TC, times[2][105], s, d, N, R, tc;
vvi	adj;

void bfs(int s, int ind) {
	memset(times[ind], -1, sizeof times[ind]);
	queue<int> q;

	q.push(s);
	times[ind][s] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : adj[u]) {
			if (times[ind][v] != -1) continue;
			times[ind][v] = times[ind][u] + 1;
			q.push(v);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> N >> R;

		adj.assign(N, vi());
		for (int i = 0; i < R; i++) {
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		cin >> s >> d;

		bfs(s, 0);
		bfs(d, 1);

		int maxTime = 0;
		for (int i = 0; i < N; i++) {
			int currTime = times[0][i] + times[1][i];
			maxTime = max(maxTime, currTime);
		}

		cout << "Case " << ++TC << ": " << maxTime << '\n';
	}
}
