#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int	topoSortsNum, verticesNum, tc, indegrees[30];
char	char3, char1, char2;
vvi	adj;
vi	topo;

void changeDegrees(int u, int d) {
	indegrees[u] += d;
	for (int i = 0; i < (int) adj[u].size(); i++) {
		indegrees[adj[u][i]] += d;
	}
}

void topoSort () {
	if ((int)topo.size() >= verticesNum) {
		for (int i = 0; i < verticesNum; i++) cout << (i ? " " : "") << (char) ('A' + topo[i]);
		cout << '\n';
		topoSortsNum++;
		return;
	}

	for (int i = 0; i < 30; i++) {
		if (!indegrees[i]) {
			topo.push_back(i);
			changeDegrees(i, -1);
			topoSort();
			changeDegrees(i, 1);
			topo.pop_back();
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc; cin.ignore();
	while (tc--) {
		verticesNum = topoSortsNum = 0;
		memset(indegrees, -1, sizeof indegrees);
		adj.assign(30, vi());

		cin.ignore();
		do {
			verticesNum++;
			char1 = cin.get();
			indegrees[char1 - 'A'] = 0;
			if (verticesNum == 100) break;
		} while ((char2 = cin.get()) != '\n');

		do {
			char1 = cin.get();
			cin.ignore();
			char2 = cin.get();

			adj[char1 - 'A'].push_back(char2 - 'A');
			indegrees[char2 - 'A']++;
		} while (!cin.eof() && cin.get() != '\n');

		topoSort();
		if (!topoSortsNum) cout << "NO\n";
		if (tc) cout << '\n';
	}
}
