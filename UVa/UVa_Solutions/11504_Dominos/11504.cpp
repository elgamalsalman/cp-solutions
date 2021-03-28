#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef stack<int> si;

int	knocks, dfsCounter, dfsNum[100050], dfsLow[100050], tc, n, m;
vvi	adj;
si	dfsStack;
bitset<100050>	inStack, inScc;

void findScc (int u) {
	dfsNum[u] = dfsLow[u] = ++dfsCounter;
	dfsStack.push(u);
	inStack[u] = 1;
	
	for (int i = 0; i < (int) adj[u].size(); i++) {
		int v = adj[u][i];

		if (dfsNum[v] == -1) findScc(v);
		if (inStack[v]) dfsLow[u] = min(dfsLow[u], dfsLow[v]);
	}

	if (dfsNum[u] == dfsLow[u]) {
		int numEles = 0; inScc.reset(); inScc[u] = 1;
		while (1) {
			int ele = dfsStack.top(); dfsStack.pop();
			inStack[ele] = 0;
			numEles++;

			for (int i = 0; i < (int) adj[ele].size(); i++) {
				inScc[adj[ele][i]] = 1;
			}

			if (u == ele) break;
		}
		if ((int) inScc.count() == numEles) knocks++;
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> n >> m;

		knocks = dfsCounter = 0;
		memset(dfsNum, -1, sizeof dfsNum);
		adj.assign(n + 20, vi());

		int u, v;
		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			adj[v].push_back(u);
		}

		for (int i = 1; i <= n; i++) {
			if (dfsNum[i] == -1) findScc(i);
		}

		cout << knocks << '\n';
	}
}
