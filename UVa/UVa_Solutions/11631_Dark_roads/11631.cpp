#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define ww first
#define vv second

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int	totalLen, MSTLen, x, y, z, n, m;
vvii	adj;
priority_queue<ii, vii, greater<ii>>	edges;
bitset<200050>	taken;

void take (int u) {
	taken[u] = 1;
	for (int i = 0; i < (int) adj[u].size(); i++) {
		edges.push(adj[u][i]);
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> m >> n, m || n) {
		totalLen = MSTLen = 0;
		taken.reset();
		adj.assign(m, vii());

		for (int i = 0; i < n; i++) {
			cin >> x >> y >> z;
			adj[x].push_back({z, y});
			adj[y].push_back({z, x});
			totalLen += z;
		}

		take(0);
		while (!edges.empty()) {
			ii edge = edges.top(); edges.pop();
			if (!taken[edge.vv]) {
				take(edge.vv);
				MSTLen += edge.ww;
			}
		}

		cout << totalLen - MSTLen << '\n';
	}
}
