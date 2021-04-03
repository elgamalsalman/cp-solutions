#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

int	MSTWeight, currSecMSTWeight, secMSTWeight, tc, N, M, A, B, C;
vi	MSTEdges;
viii	edges;

class UFDS {
	int	numSets;
	vi	p, h;
	public:
		UFDS (int n) : numSets(n) {
			h.assign(n + 20, 1); p.resize(n + 20);
			for (int i = 1; i <= n; i++) p[i] = i;
		}

		int findSet (int u) {return (u == p[u] ? u : p[u] = findSet(p[u]));}
		int isSameSet (int u, int v) {return (findSet(u) == findSet(v));}
		void unionSet (int u, int v) {
			u = findSet(u); v = findSet(v);
			if (u == v) return;

			numSets--;
			if (h[u] > h[v]) p[v] = u;
			else {
				p[u] = v;
				if (h[u] == h[v]) h[v]++;
			}
		}

		bool isValid () {return (numSets == 1);}
};

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> N >> M;
		edges.resize(M);
		MSTEdges.clear();
		MSTWeight = 0;
		secMSTWeight = 3000000;

		for (int i = 0; i < M; i++) {
			cin >> A >> B >> C;
			edges[i] = {C, {A, B}};
		}
		sort(edges.begin(), edges.end());

		UFDS MSTNetwork(N);
		for (int i = 0; i < M; i++) {
			iii edge = edges[i];
			if (!MSTNetwork.isSameSet(edge.se.fi, edge.se.se)) {
				MSTWeight += edge.fi;
				MSTEdges.push_back(i);
				MSTNetwork.unionSet(edge.se.fi, edge.se.se);
			}
		}

		for (int removedEdgeInd : MSTEdges) {
			currSecMSTWeight = 0;

			UFDS secMSTNetwork(N);
			for (int i = 0; i < M; i++) {
				if (i == removedEdgeInd) continue;
				iii edge = edges[i];
				if (!secMSTNetwork.isSameSet(edge.se.fi, edge.se.se)) {
					currSecMSTWeight += edge.fi;
					secMSTNetwork.unionSet(edge.se.fi, edge.se.se);
				}
			}

			if (secMSTNetwork.isValid() && currSecMSTWeight < secMSTWeight) secMSTWeight = currSecMSTWeight;
		}

		cout << MSTWeight << ' ' << secMSTWeight << '\n';
	}
}
