#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int	maxSegmentsNum, k, n;
vii	distances;

class DSU {
	int n, sizesCount[100050], diffSizesCount = 0;
	vi setSize, p, h;
	bitset<100050> activatedNodes;

	void incSizeCount(int s) {
		sizesCount[s]++;
		if (sizesCount[s] == 1) diffSizesCount++;
	}

	void decSizeCount(int s) {
		sizesCount[s]--;
		if (!sizesCount[s]) diffSizesCount--;
	}

	public:

		int segmentsNum = 0;

		DSU(int _n) : n{_n} {
			setSize.assign(n, 1);
			h.assign(n, 0);
			activatedNodes.reset();
			memset(sizesCount, 0, sizeof sizesCount);
			for (int i = 0; i < n; i++) p.push_back(i);
		}

		void activate(int u) {
			activatedNodes[u] = 1;
			incSizeCount(1);
			segmentsNum++;
			if (u && activatedNodes[u - 1]) unionSet(u, u - 1);
			if (u < n - 1 && activatedNodes[u + 1]) unionSet(u, u + 1);
		}

		int findSet(int u) { return (p[u] == u ? u : p[u] = findSet(p[u])); }
		bool isSameSet(int u, int v) { return (findSet(u) == findSet(v)); }
		void unionSet(int u, int v) {
			u = findSet(u);
			v = findSet(v);
			if (u == v) return;
			segmentsNum--;
			if (h[u] > h[v]) {
				p[v] = u;
				decSizeCount(setSize[v]);
				decSizeCount(setSize[u]);
				setSize[u] += setSize[v];
				incSizeCount(setSize[u]);
			} else {
				p[u] = v;
				if (h[u] == h[v]) h[v]++;
				decSizeCount(setSize[v]);
				decSizeCount(setSize[u]);
				setSize[v] += setSize[u];
				incSizeCount(setSize[v]);
			}
		}
		bool areSegmentsEqual() { return (diffSizesCount == 1); }
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		distances.push_back({tmp, i});
	}
	
	sort(distances.begin(), distances.end());

	DSU dsu(n);
	for (int i = 0; i < n; i++) {
		dsu.activate(distances[i].se);
		if (dsu.areSegmentsEqual() && dsu.segmentsNum > maxSegmentsNum) {
			maxSegmentsNum = dsu.segmentsNum;
			k = distances[i].fi + 1;
		}
	}

	cout << k << '\n';
}
