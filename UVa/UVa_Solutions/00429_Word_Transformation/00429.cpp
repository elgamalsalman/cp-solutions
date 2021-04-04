#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int	dis[205], diffs, n, tc;
string	a, b, words[205];
vvi	adj;

int bfs (int u, int v) {
	queue<int> q;
	q.push(u);

	while (!q.empty()) {
		int start = q.front(); q.pop();
		for (int i = 0; i < (int)adj[start].size(); i++) {
			int end = adj[start][i];
			if (dis[end] == -1) {
				dis[end] = dis[start] + 1;
				q.push(end);
				if (end == v) return dis[end];
			}
		}
	} 
}

int findInd (string word) {
	for (int i = 0; i < n; i++) 
		if (words[i] == word)
			return i;
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc; cin.ignore();
	while (tc--) {
		n = 0;

		cin.ignore();
		while (cin.peek() != '*') {
			cin >> words[n++];
			cin.ignore();
		} cin.ignore(2);

		adj.assign(n + 20, vi());
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (words[i].size() != words[j].size()) continue;
				diffs = 0;
				for (int k = 0; k < (int)words[i].size(); k++) {
					if (words[i][k] != words[j][k]) diffs++;
				}

				if (diffs == 1) {
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}

		while (cin.peek() != '\n' && cin >> a >> b) {
			int u = findInd(a), v = findInd(b);

			memset(dis, -1, sizeof dis);
			dis[u] = 0;
			cout << a << ' ' << b << ' ' << bfs(u, v) << '\n';
			cin.ignore();
		}

		if (tc) cout << '\n';
	}
}
