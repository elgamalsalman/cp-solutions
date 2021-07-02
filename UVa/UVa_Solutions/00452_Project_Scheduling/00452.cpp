#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int	dp[30], maxDuration, tc, durations[30];
vi	transAdj[30], adj[30];

int prop(int u) {
	if (dp[u] != -1) return dp[u];
	dp[u] = durations[u];
	for (int v : transAdj[u]) dp[u] = max(dp[u], durations[u] + prop(v));
	maxDuration = max(maxDuration, dp[u]);
	return dp[u];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> tc; cin.ignore(1);
	while (tc--) {
		memset(durations, 0, sizeof durations);
		memset(dp, -1, sizeof dp);
		for (int i = 0; i < 30; i++) adj[i].clear();
		for (int i = 0; i < 30; i++) transAdj[i].clear();

		cin.ignore(1);
		while (cin.peek() != EOF && cin.peek() != '\n') {
			char task = cin.get();
			cin >> durations[task - 'A'];
			while (cin.peek() == ' ') cin.ignore();
			while (cin.peek() != EOF && cin.peek() != '\n') {
				char prereq = cin.get();
				adj[task - 'A'].push_back(prereq - 'A');
				transAdj[prereq - 'A'].push_back(task - 'A');
			}
			cin.ignore();
		}

		maxDuration = 0;
		for (int i = 0; i < 30; i++) if (!adj[i].size()) {
			prop(i);
		}

		cout << maxDuration << (tc ? "\n\n" : "\n");
	}
}
