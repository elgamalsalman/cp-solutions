#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int	n, m;
vii	edges;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v; u--; v--;
		edges.push_back({u, v});
		edges.push_back({v, u});
	}

	sort(edges.begin(), edges.end());

	for (int i = 2; i <= n; i++) {
		if (n % i) continue;

		bool valid = 1;
		int step = n / i;
		for (int j = 0; j < 2*m; j++) {
			if (!binary_search(edges.begin(), edges.end(), ii{(edges[j].fi + step) % n, (edges[j].se + step) % n})) {
				valid = 0;
				break;
			}
		}

		if (valid) { cout << "Yes\n"; return 0; }
	}

	cout << "No\n";
}
