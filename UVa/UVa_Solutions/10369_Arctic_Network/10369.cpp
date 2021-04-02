#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define ww fi
#define uu se.fi
#define vv se.se
#define xx fi
#define yy se

typedef pair<int, int> ii;
typedef pair<double, ii> dii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<dii> vdii;

int	E, tc, S, P, x, y;
ii	pos[505];
dii	edges[250050];

class UFDS {
	int	setsNum, n;
	vi	p, h;
	public:
		UFDS (int _n) : setsNum(_n) , n(_n) {
			h.assign(n, 1);
			for (int i = 0; i < n; i++) p.push_back(i);
		}

		int findSet (int u) {
			return (p[u] == u ? u : p[u] = findSet(p[u]));
		}

		bool isSameSet (int u, int v) {return (findSet(u) == findSet(v));}

		void unionSet (int u, int v) {
			u = findSet(u); v = findSet(v);
			if (isSameSet(u, v)) return;

			setsNum--;
			if (h[u] > h[v]) p[v] = u;
			else {
				p[u] = v;
				if (h[u] == h[v]) h[v]++;
			}
		}
		
		int getSetsNum () {return setsNum;}
};

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		E = 0;

		cin >> S >> P;
		for (int i = 0; i < P; i++) {
			cin >> x >> y;
			pos[i] = {x, y};
		}

		for (int i = 0; i < P; i++) {
			for (int j = i + 1; j < P; j++) {
				edges[E++] = {hypot(pos[i].xx - pos[j].xx, pos[i].yy - pos[j].yy), {i, j}};
			}
		}

		sort(edges, edges + E);

		UFDS network(P);
		int i = 0; if (!S) S = 1;
		for (;i < E; i++) {
			if (network.getSetsNum() <= S) break;
			dii edge = edges[i];
			if (!network.isSameSet(edge.uu, edge.vv))
				network.unionSet(edge.uu, edge.vv);
		}
		
		cout << fixed << setprecision(2) << round(edges[i - 1].ww * 100)/100.0 << '\n';
	}
}
