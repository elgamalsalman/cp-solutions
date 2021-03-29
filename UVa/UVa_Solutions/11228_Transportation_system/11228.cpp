#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define x first
#define y second
#define w first
#define u second.first
#define v second.second

typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef pair<double, ii> dii;
typedef vector<int> vi;

int	states, tc, tcNum, edgesCounter, n, r;
double	rail, road;
dd	pos[1050];
dii	edges[500000];

class UFDS {
	vi	p, h;
	int	n;

	public:
		 UFDS (int _n) {
			 n = _n;
			 p.resize(n, 0), h.assign(n, 1);
			 for (int i = 0; i < n; i++) p[i] = i;
		 }

		 int findSet (int i) {
			 return (p[i] == i ? i : p[i] = findSet(p[i]));
		 }

		 bool isSameSet (int i, int j) {return findSet(i) == findSet(j);}

		 void unionSet (int i, int j) {
			 i = findSet(i); j = findSet(j);
			 if (!isSameSet(i, j)) {
				 if (h[i] > h[j]) {
					 p[j] = i;
				 } else {
					 p[i] = j;
					 if (h[i] == h[j]) h[j]++;
				 }
			 }
		 }
};

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		rail = road = 0;
		states = 1;

		cin >> n >> r;
		for (int i = 0; i < n; i++) {
			cin >> pos[i].x >> pos[i].y;
		}

		edgesCounter = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				edges[edgesCounter++] = {hypot(pos[i].x - pos[j].x, pos[i].y - pos[j].y), {i, j}};
			}
		}

		sort(edges, edges + edgesCounter);
		UFDS network(n);
		for (int i = 0; i < edgesCounter; i++) {
			if (!network.isSameSet(edges[i].u, edges[i].v)) {
				if (edges[i].w > r) {
					rail += edges[i].w;
					states++;
				} else road += edges[i].w;
				network.unionSet(edges[i].u, edges[i].v);
			}
		}

		cout << "Case #" << ++tcNum << ": " << states << ' ' << round(road) << ' ' << round(rail) << '\n';
	}
}
