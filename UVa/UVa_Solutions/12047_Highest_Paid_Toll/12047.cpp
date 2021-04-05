#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int	ans, dis1[10050], dis2[10050], tc, N, M, s, t, p;
vvii	adj1, adj2;

void dijkstra (int source, int (&dis)[10050], const vvii &adj) {
	fill(dis, dis + 10050, 1e9);
	dis[source] = 0;
	priority_queue<ii, vii, greater<ii>> pq;
	pq.push({dis[source], source});
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		if (front.fi > dis[front.se]) continue;
		for (int i = 0; i < (int)adj[front.se].size(); i++) {
			ii edge = adj[front.se][i];
			if (front.fi + edge.fi < dis[edge.se]) {
				dis[edge.se] = front.fi + edge.fi;
				pq.push({dis[edge.se], edge.se});
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> N >> M >> s >> t >> p;
		adj1.assign(N + 20, vii());
		adj2.assign(N + 20, vii());

		for (int i = 0; i < M; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			adj1[u].push_back({w, v});
			adj2[v].push_back({w, u});
		}

		dijkstra(s, dis1, adj1);
		dijkstra(t, dis2, adj2);

		ans = -1;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < (int)adj1[i].size(); j++) {
				if (dis1[i] != 1e9 && dis2[adj1[i][j].se] != 1e9 && adj1[i][j].fi + dis1[i] + dis2[adj1[i][j].se] <= p) ans = max(ans, adj1[i][j].fi);
			}
		}

		cout << ans << '\n';
	}
}
