#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<string, int> msi;

int	tc, indegree[105], M, N;
string	s, s1, s2, beverages[105];
msi	dictionary;
vvi	adj;
vi	topo;

void topoSort () {
	for (int i = 0; i < N; i++) {
		if (!indegree[i]) {
			topo.push_back(i); indegree[i]--;
			for (int j : adj[i]) indegree[j]--;
			i = -1;
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> N) {
		topo.clear();
		dictionary.clear();
		adj.assign(N + 20, vi());
		memset(indegree, 0, sizeof indegree);

		for (int i = 0; i < N; i++) {
			cin >> s;
			dictionary[s] = i;
			beverages[i] = s;
		}
		
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> s1 >> s2;
			adj[dictionary[s1]].push_back(dictionary[s2]);
			indegree[dictionary[s2]]++;
		}

		topoSort();

		cout << "Case #" << ++tc << ": Dilbert should drink beverages in this order:";
		for (int i = 0; i < N; i++) {
			cout << ' ' << beverages[topo[i]];
		}
		cout << ".\n\n";
	}
}
