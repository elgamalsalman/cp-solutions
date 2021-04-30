#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define cc first
#define vv second

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

ll	totalCost, n;
vvii	adj;
bitset<500050>	visited;
priority_queue<ii>	pq;

void process(int u) {
	visited[u] = 1;
	for (ii edge : adj[u]) {
		if (visited[edge.vv]) continue;
		pq.push(edge);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	adj.assign(n * 4, vii());
	for (int i = 0; i < n; i++) {
		int c, e1, e2, e3, e4;
		cin >> c >> e1 >> e2 >> e3 >> e4;

		adj[i * 2].push_back({0, e1 + 2*n - 1});
		adj[e1 + 2*n - 1].push_back({0, i * 2});
		adj[i * 2].push_back({0, e2 + 2*n - 1});
		adj[e2 + 2*n - 1].push_back({0, i * 2});

		adj[i * 2 + 1].push_back({0, e3 + 2*n - 1});
		adj[e3 + 2*n - 1].push_back({0, i * 2 + 1});
		adj[i * 2 + 1].push_back({0, e4 + 2*n - 1});
		adj[e4 + 2*n - 1].push_back({0, i * 2 + 1});

		adj[i * 2].push_back({-c, i * 2 + 1});
		adj[i * 2 + 1].push_back({-c, i * 2});
	}

	// Prim's algorithm
	process(0);
	while (!pq.empty()) {
		ii top = pq.top(); pq.pop();
		if (!visited[top.vv]) {
			totalCost += -top.cc;
			process(top.vv);
		}
	}

	cout << totalCost << '\n';
}
