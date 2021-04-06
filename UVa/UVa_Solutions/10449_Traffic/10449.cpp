#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int	tcNum, earn1[250], earn2[250], q, qNum, a, b, n, busyness[250], r;
vvii	adj;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n) {
		for (int i = 1; i <= n; i++) cin >> busyness[i];
		adj.assign(n + 20, vii());
		cin >> r;
		for (int i = 0; i < r; i++) {
			cin >> a >> b;
			adj[a].push_back({pow(busyness[b] - busyness[a], 3), b});
		}

		fill(earn1, earn1 + 250, 1e9);
		fill(earn2, earn2 + 250, 1e9);
		earn1[1] = 0; earn2[1] = 0;
		for (int i = 0; i < n; i++) {
			for (int u = 1; u <= n; u++) {
				for (ii edge : adj[u]) {
					if (earn1[u] + edge.fi < earn1[edge.se]) {
						earn1[edge.se] = earn2[edge.se] = earn1[u] + edge.fi;
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int u = 1; u <= n; u++) {
				for (ii edge : adj[u]) {
					if (earn2[u] + edge.fi < earn2[edge.se]) {
						earn2[edge.se] = earn2[u] + edge.fi;
					}
				}
			}
		}


		cout << "Set #" << ++tcNum << '\n';

		cin >> qNum;
		for (int i = 0; i < qNum; i++) {
			cin >> q;
			if (earn1[q] < 3 || earn1[q] >= 1e8 || earn2[q] < earn1[q]) cout << "?\n";
			else cout << earn1[q] << '\n';
		}
	}
}
