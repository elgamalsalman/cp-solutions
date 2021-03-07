#include<bits/stdc++.h>

using namespace std;

#define UNVISITED -1
#define VISITED -2

int	dfsCounter, dfsNum[50050], mx, tcNum, rec[50050], tc, N, seens[50050];

void dfs(int u) {
	dfsNum[u] = dfsCounter++;
	int v = rec[u];

	if (dfsNum[v] == UNVISITED) {
		dfs(v);
		if (seens[u] == -1) seens[u] = seens[v] + 1;
	} else if (dfsNum[v] == VISITED) {
		seens[u] = seens[v] + 1;
	} else {
		int loopSeens = dfsCounter - dfsNum[v];
		int y = v;
		do {
			seens[y] = loopSeens;
			y = rec[y];
		} while (y != v);
	}
	dfsNum[u] = VISITED;
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		dfsCounter = 0;
		memset(seens, -1, sizeof seens);
		memset(dfsNum, UNVISITED, sizeof dfsNum);

		cin >> N;
		for (int i = 0; i < N; i++) {
			int u, v;
			cin >> u >> v;
			rec[u] = v;
		}

		mx = 1;
		for (int i = 1; i <= N; i++) {
			if (seens[i] == UNVISITED) dfs(i);
			if (seens[i] > seens[mx]) mx = i;
		}

		cout << "Case " << ++tcNum << ": " << mx << '\n';
	}
}
