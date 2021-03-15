#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int	p, n, leaves[100050];
vvi	adj;

int countLeaves (int u) {
	if (adj[u].empty()) return leaves[u] = 1;
	for (int i = 0; i < (int)adj[u].size(); i++) {
		leaves[u] += countLeaves(adj[u][i]);
	}
	return leaves[u];
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	adj.resize(n + 50);
	for (int i = 2; i <= n; i++) {
		cin >> p;
		adj[p].push_back(i);
	}
	
	countLeaves(1);

	sort(leaves + 1, leaves + 1 + n);
	for (int i = 1; i <= n; i++) {
		cout << (i == 1 ? "" : " ") << leaves[i];
	} cout << '\n';
}
