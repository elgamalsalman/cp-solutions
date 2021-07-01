#include <bits/stdc++.h>

using namespace std;

int	tc, adj[55][55], nameCounter, P, R;
map<string, int>	nameToIndMap;

int nameToInd(string name) {
	if (!nameToIndMap[name]) nameToIndMap[name] = nameCounter++;
	return nameToIndMap[name];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> P >> R && (P || R)) {
		nameToIndMap.clear();
		memset(adj, -1, sizeof adj);
		nameCounter = 1;
		for (int i = 0; i < R; i++) {
			string p1, p2;
			cin >> p1 >> p2;
			adj[nameToInd(p1)][nameToInd(p2)] = 1;
			adj[nameToInd(p2)][nameToInd(p1)] = 1;
		}

		for (int k = 1; k < nameCounter; k++)
			for (int i = 1; i < nameCounter; i++)
				for (int j = 1; j < nameCounter; j++) {
					if (adj[i][k] == -1 || adj[k][j] == -1) continue;
					if (adj[i][j] == -1 || adj[i][k] + adj[k][j] < adj[i][j]) adj[i][j] = adj[i][k] + adj[k][j];
				}

		int maxDis = 0;
		bool isConnected = 1;
		if (nameCounter != P + 1) isConnected = 0;
		for (int i = 1; i < nameCounter; i++) {
			for (int j = 1; j < nameCounter; j++) {
				if (i == j) continue;
				if (adj[i][j] == -1) isConnected = 0;
				if (adj[i][j] > maxDis) maxDis = adj[i][j];
			}
		}

		cout << "Network " << ++tc << ": ";
		if (isConnected) cout << maxDis << "\n\n";
		else cout << "DISCONNECTED\n\n";
	}
}
