#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

class DSU {
	int	n;
	vi	p, h;
	
	public:
		int	setsCount;

		DSU(int _n) : n{_n} {
			h.assign(n, 0);
			for (int i = 0; i < n; i++) p.push_back(i);
			setsCount = n;
		}

		int findSet(int u) { return (p[u] == u ? u : p[u] = findSet(p[u])); }
		bool isSameSet(int u, int v) { return (findSet(u) == findSet(v)); }
		void unionSet(int u, int v) {
			u = findSet(u); v = findSet(v);
			if (u == v) return;

			setsCount--;
			if (h[u] > h[v]) {
				p[v] = u;
			} else {
				p[u] = v;
				if (h[u] == h[v]) h[v]++;
			}
		}
};

ll	totalWeight, tc, n, p, a[200050];
ii	b[200050];
DSU dsu(0);

void propagate(int ind) {
	int base = a[ind];
	for (int i = ind - 1; i >= 0; i--) {
		if (a[i] % base || dsu.isSameSet(i, ind)) break;
		dsu.unionSet(i, ind);
		totalWeight += base;
	}

	for (int i = ind + 1; i < n; i++) {
		if (a[i] % base || dsu.isSameSet(i, ind)) break;
		dsu.unionSet(i, ind);
		totalWeight += base;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		totalWeight = 0;

		cin >> n >> p;
		dsu = DSU(n);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = {a[i], i};
		}

		sort(b, b + n);

		for (int i = 0; i < n; i++) {
			if (b[i].fi > p) break;
			
			propagate(b[i].se);
		}

		totalWeight += p * (dsu.setsCount - 1);
		cout << totalWeight << '\n';
	}
}
