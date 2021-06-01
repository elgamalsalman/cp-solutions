#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
bitset<1050> visited;

int	k1, k2, firstContactV, myTree[1050], liTree[1050], tc, n;
vvi	adj;

void dfs(int source) {
	for (int i = 0; i < k1; i++) {
		if (source == myTree[i]) {
			firstContactV = source;
			return;
		}
	}

	visited[source] = 1;
	for (int v : adj[source]) {
		if (visited[v]) continue;
		dfs(v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> n;
		adj.assign(n + 20, vi());
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		cin >> k1;
		for (int i = 0; i < k1; i++) cin >> myTree[i];

		cin >> k2;
		for (int i = 0; i < k2; i++) cin >> liTree[i];

		cout << "B " << liTree[0] << '\n';
		cout.flush();

		int source;
		cin >> source;

		firstContactV = -1;
		visited.reset();
		dfs(source);

		int liContact;
		cout << "A " << firstContactV << '\n';
		cout.flush();
		cin >> liContact;

		bool areOverlapping = 0;
		for (int i = 0; i < k2; i++) {
			if (liContact == liTree[i]) {
				areOverlapping = 1;
			}
		}

		if (areOverlapping) {
			cout << "C " << firstContactV << '\n';
			cout.flush();
		} else {
			cout << "C -1\n";
			cout.flush();
		}
	}
}
