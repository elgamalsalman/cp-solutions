#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef set<int> si;
typedef set<ii> sii;
typedef map<int, int> mii;

class DSU {
	int n, numSets;
	vi h, p, sizes;
	queue<int> ccToErase;
	mii	cc;
	public:
		DSU(int _n) : n{_n}, numSets{_n} {
			h.assign(n, 0);
			sizes.assign(n, 1);
			for (int i = 0; i < n; i++) {
				p.push_back(i);
				cc[i] = 0;
			}
		}

		int findSet(int u) {return (p[u] == u ? u : p[u] = findSet(p[u]));}
		void unionSets(int u, int v) {
			u = findSet(u); v = findSet(v);
			if (u == v) return;
			numSets--;
			if (h[u] > h[v]) {
				p[v] = u;
				sizes[u] += sizes[v];
				ccToErase.push(v);
			} else {
				p[u] = v;
				sizes[v] += sizes[u];
				if (h[u] == h[v]) h[v]++;
				ccToErase.push(u);
			}
		}

		void clearEdges() {
			for (auto it = cc.begin(); it != cc.end(); it++) {
				it->se = 0;
			}
		}

		void incEdge(int u) { cc[findSet(u)]++; }
		void joinConnected(int u) {
			for (auto it = cc.begin(); it != cc.end(); it++) {
				if (sizes[it->fi] > it->se && findSet(it->fi) != findSet(u)) {
					unionSets(it->fi, u);
				}
			}

			while (!ccToErase.empty()) {
				cc.erase(ccToErase.front());
				ccToErase.pop();
			}
		}

		int countSets() {return numSets;}
};

int	n, m, u, v, degrees[100050];
vvi	adj;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	adj.assign(n, vi());
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	DSU dsu(n);

	for (int u = 0; u < n; u++) {
		dsu.clearEdges();
		for (int v : adj[u]) dsu.incEdge(v);
		dsu.joinConnected(u);
	}

	cout << dsu.countSets() - 1 << '\n';
}
