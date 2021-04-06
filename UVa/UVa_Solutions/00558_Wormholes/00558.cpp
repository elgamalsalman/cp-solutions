#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int	dis[1050], tc, n, m, x, y, t;
vvii	adj;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		fill(dis, dis + 1050, 1e9);

		cin >> n >> m;
		adj.assign(n, vii());
		for (int i = 0; i < m; i++) {
			cin >> x >> y >> t;
			adj[x].push_back({t, y});
		}

		bool relaxed;
		for (int i = 0; i < n; i++) {
			relaxed = 0;
			for (int u = 0; u < n; u++) {
				for (ii edge : adj[u]) {
					if (dis[edge.se] > dis[u] + edge.fi) {
						dis[edge.se] = dis[u] + edge.fi;
						relaxed = 1;
					}
				}
			}
		}

		cout << (relaxed ? "possible\n" : "not possible\n");
	}
}
