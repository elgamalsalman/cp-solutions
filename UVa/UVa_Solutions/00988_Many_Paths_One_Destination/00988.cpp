#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int	dp[100050], _, numPaths, e, n;
vvi	adj;
vi	deaths;

int prop(int u) {
	if (dp[u] != -1) return dp[u];

	dp[u] = 0;
	for (int v : adj[u]) dp[u] += prop(v);

	return dp[u];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> e) {
		deaths.clear();
		adj.assign(e, vi());
		for (int i = 0; i < e; i++) {
			cin >> n;
			if (!n) deaths.push_back(i);
			for (int j = 0; j < n; j++) {
				int v;
				cin >> v;
				adj[v].push_back(i);
			}
		}
		
		numPaths = 0;
		memset(dp, -1, sizeof dp);
		dp[0] = 1;
		for (int i : deaths) numPaths += prop(i);

		cin.ignore(2);
		cout << numPaths << (cin.eof() ? "\n" : "\n\n");
	}
}
