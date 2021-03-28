#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef stack<int> si;

int	SCCRoots, dfsCounter, dfsNum[2050], dfsLow[2050], N, M, V, W, P;
vvi	adj;
si	dfsStack;
bitset<2050> inStack;

void isSCC (int u) {
	dfsNum[u] = dfsLow[u] = ++dfsCounter;
	dfsStack.push(u);
	inStack[u] = 1;

	for (int i = 0; i < (int) adj[u].size(); i++) {
		int v = adj[u][i];

		if (dfsNum[v] == -1) isSCC(v);
		if (inStack[v]) dfsLow[u] = min(dfsLow[u], dfsLow[v]);
	}

	if (dfsNum[u] == dfsLow[u]) {
		SCCRoots++;
		while (1) {
			int ele = dfsStack.top();
			dfsStack.pop();
			inStack[ele] = 0;
			if (u == ele) break;
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> N >> M, N || M) {
		SCCRoots = dfsCounter = 0;
		adj.assign(N + 20, vi());
		inStack.reset();
		memset(dfsNum, -1, sizeof dfsNum);

		for (int i = 0; i < M; i++) {
			cin >> V >> W >> P;
			adj[V].push_back(W);
			if (P == 2) adj[W].push_back(V);
		}

		for (int i = 1; i <= N; i++) {
			if (dfsNum[i] == -1) isSCC(i);
		}

		cout << (SCCRoots <= 1) << '\n';
	}
}
