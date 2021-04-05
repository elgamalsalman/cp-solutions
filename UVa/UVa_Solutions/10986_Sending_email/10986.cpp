#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define ww fi
#define vv second

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int	dis[20050], tcNum, tc, n, m, S, T, a, b, w;
vvii	adj;

void dijkstra () {
	fill(dis, dis + n, 1e9);
	dis[S] = 0;
	priority_queue<ii, vii, greater<ii>> pq;
	pq.push({dis[S], S});
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		if (front.ww > dis[front.vv]) continue;
		for (int i = 0; i < (int)adj[front.vv].size(); i++) {
			ii edge = adj[front.vv][i];
			if (front.ww + edge.ww < dis[edge.vv]) {
				dis[edge.vv] = front.ww + edge.ww;
				pq.push({dis[edge.vv], edge.vv});
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> n >> m >> S >> T;

		adj.assign(n, vii());
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> w;
			adj[a].push_back({w, b});
			adj[b].push_back({w, a});
		}

		dijkstra();

		cout << "Case #" << ++tcNum << ": ";
		if (dis[T] == 1e9) cout << "unreachable";
		else cout << dis[T];
		cout << '\n';
	}
}
