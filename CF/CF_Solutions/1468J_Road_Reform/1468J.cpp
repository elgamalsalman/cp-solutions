#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define ww first
#define vv second

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

ll	exceeds, leastDiff, tc, n, m, k;
vvii	adj;
bitset<200050>	taken;
priority_queue<ii>	pq;

void process(int u) {
	taken[u] = 1;
	for (ii edge : adj[u]) {
		if (!taken[edge.vv]) pq.push(edge);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		leastDiff = 1e18;
		exceeds = 0;
		taken.reset();

		cin >> n >> m >> k;
		adj.assign(n + 1, vii());
		int u, v, w;
		for (int i = 0; i < m; i++) {
			cin >> u >> v >> w;
			adj[u].push_back({-w, v});
			adj[v].push_back({-w, u});
			if (leastDiff > abs(w - k)) leastDiff = abs(w - k);
		}

		process(1);
		while (!pq.empty()) {
			ii edge = pq.top(); pq.pop();
			if (taken[edge.vv]) continue;
			process(edge.vv);
			exceeds += max(0LL, -(edge.ww + k));
		}

		if (exceeds == 0) cout << leastDiff << '\n';
		else cout << exceeds << '\n';
	}
}
