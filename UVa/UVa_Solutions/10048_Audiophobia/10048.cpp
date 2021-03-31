#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;

int	tc, ans, c1, c2, d, C, S, Q;
vvii	MSTAdj, adj;
bitset<105>	taken, visited;
priority_queue<iii, viii, greater<iii>>	edges;

int findMaxEdge (int u, int v) {
	//cerr << "// findMaxEdge(" << u << ", " << v << ")\n";
	if (u == v) return 0;
	if (visited[u]) return -1;

	visited[u] = 1;

	for (int i = 0; i < (int) MSTAdj[u].size(); i++) {
		ii edge = MSTAdj[u][i];
		//cerr << "// edge to : " << edge.se << '\n';
		int subMax = findMaxEdge(edge.se, v);
		if (subMax != -1) return max(edge.fi, subMax);
	}

	return -1;
}

void take (int u) {
	taken[u] = 1;
	for (int i = 0; i < (int) adj[u].size(); i++) {
		ii edge = adj[u][i];
		if (!taken[edge.se]) edges.push({edge.fi, {u, edge.se}});
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> C >> S >> Q, C || S || Q) {
		MSTAdj.assign(C + 20, vii());
		adj.assign(C + 20, vii());
		taken.reset();

		if (tc++) cout << '\n';
		cout << "Case #" << tc << '\n';

		for (int i = 0; i < S; i++) {
			cin >> c1 >> c2 >> d;
			adj[c1].push_back({d, c2});
			adj[c2].push_back({d, c1});
		}

		for (int i = 1; i <= C; i++) {
			if (taken[i]) continue;
			take(i);
			while (!edges.empty()) {
				iii edge = edges.top(); edges.pop();
				if (!taken[edge.se.se]) {
					take(edge.se.se);
					MSTAdj[edge.se.fi].push_back({edge.fi, edge.se.se});
					MSTAdj[edge.se.se].push_back({edge.fi, edge.se.fi});
				}
			}
		}
		
		for (int i = 0; i < Q; i++) {
			cin >> c1 >> c2;
			visited.reset();
			ans = findMaxEdge(c1, c2);
			if (ans == -1) cout << "no path\n";
			else cout << ans << '\n';
		}
	}
}
