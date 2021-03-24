#include<bits/stdc++.h>

using namespace std;

#define planet first
#define time second

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int	sssp[100050], k, n, m, a, b, t;
vvii	adj;
vvi	busy;

void bfs () {
	memset(sssp, -1, sizeof sssp);
	sssp[1] = 0;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int u = q.front(); q.pop();

		
		// calculate time delay in planet
		int delay = 0;
		bool isBusy = 0;
		for (int i = 0; i < (int)busy[u].size(); i++) {
			if (busy[u][i] == sssp[u]) isBusy = 1;
			if (isBusy && (!delay || busy[u][i] == busy[u][i - 1] + 1)) delay++;
		}

		for (int i = 0; i < (int) adj[u].size(); i++) {
			ii v = adj[u][i];
			if (sssp[v.planet] == -1 || sssp[v.planet] > sssp[u] + delay + v.time) {
				sssp[v.planet] = sssp[u] + delay + v.time;
				q.push(v.planet);
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	adj.resize(n + 50); busy.resize(n + 50);
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> t;
		adj[a].push_back({b, t});
		adj[b].push_back({a, t});
	}

	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> t;
			busy[i].push_back(t);
		}
	}

	bfs();
	
	cout << sssp[n] << '\n';
}
