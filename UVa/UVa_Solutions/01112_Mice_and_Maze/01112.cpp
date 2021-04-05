#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define ww fi
#define vv se

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int	ans, dis[105], a, b, w, tc, N, E, T, M;
vvii	adj;

void dijkstra () {
	fill(dis + 1, dis + N + 1, 1e9);
	dis[E] = 0;

	priority_queue<ii> pq;
	pq.push({dis[E], E});
	while (!pq.empty()) {
		ii u = pq.top(); pq.pop();
		if (u.ww > dis[u.vv]) continue;
		for (int i = 0; i < (int)adj[u.vv].size(); i++) {
			ii v = adj[u.vv][i];
			if (u.ww + v.ww < dis[v.vv]) {
				dis[v.vv] = u.ww + v.ww;
				pq.push({dis[v.vv], v.vv});
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> N >> E >> T >> M;
		
		adj.assign(N + 20, vii());
		for (int i = 0; i < M; i++) {
			cin >> a >> b >> w;
			adj[b].push_back({w, a});
		}

		dijkstra();

		ans = 0;
		for (int i = 1; i <= N; i++) if (dis[i] <= T) ans++;

		cout << ans << '\n';
		if (tc) cout << '\n';
	}
}
