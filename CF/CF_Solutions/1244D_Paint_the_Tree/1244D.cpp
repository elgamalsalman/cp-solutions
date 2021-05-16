#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

ll	ansColours[100050], colours[100050], degrees[100050], minCost = 1e18, n, colourCost[3][100050];
vvi	adj;
bitset<100050>	visited;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> colourCost[0][i];
	for (int i = 1; i <= n; i++) cin >> colourCost[1][i];
	for (int i = 1; i <= n; i++) cin >> colourCost[2][i];

	memset(degrees, 0, sizeof degrees);
	adj.assign(n + 20, vi());
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		degrees[u]++;
		degrees[v]++;
	}

	vi leaves;
	for (int i = 1; i <= n; i++) if (degrees[i] == 1) leaves.push_back(i);

	if (leaves.size() != 2) {
		cout << "-1\n";
		return 0;
	}

	int pattern[] = {0, 1, 2};
	do {
		ll currCost = 0, currColourInd = 0;
		visited.reset();

		int u, v = leaves[0];
		do {
			u = v;
			visited[u] = 1;
			colours[u] = pattern[currColourInd];
			currCost += colourCost[pattern[currColourInd]][u];
			currColourInd = (currColourInd + 1) % 3;
			if (!visited[adj[u][0]]) v = adj[u][0];
			else if (adj[u].size() > 1 && !visited[adj[u][1]]) v = adj[u][1];
		} while (u != v);

		if (minCost > currCost) {
			minCost = currCost;
			copy(colours, colours + 100050, ansColours);
		}
	} while (next_permutation(pattern, pattern + 3));

	cout << minCost << '\n';
	for (int i = 1; i <= n; i++) {
		cout << ansColours[i] + 1 << " \n"[i == n];
	}
}
