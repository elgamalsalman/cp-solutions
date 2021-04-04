#include <bits/stdc++.h>

using namespace std;

#define rr first
#define cc second

typedef pair<int, int> ii;
typedef vector<ii> vii;

int	dr[] = {0, -1, 0, 1}, dc[] = {1, 0, -1, 0}, dis[2050][2050], p2, p1;
vii	mall1, mall2;

int bfs () {
	queue<ii> q;
	memset(dis, -1, sizeof dis);
	for (ii start : mall1) {
		dis[start.rr][start.cc] = 0;
		q.push(start);
	}

	for (ii dest : mall2) dis[dest.rr][dest.cc] = -2;

	while (!q.empty()) {
		ii u = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			ii v = {u.rr + dr[i], u.cc + dc[i]};
			if (v.rr < 0 || v.rr > 2000 || v.cc < 0 || v.cc > 2000 || dis[v.rr][v.cc] >= 0) continue;
			if (dis[v.rr][v.cc] == -2) {
				return dis[u.rr][u.cc] + 1;
			}

			dis[v.rr][v.cc] = dis[u.rr][u.cc] + 1;
			q.push(v);
		}
	}

	return -1;
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> p1, p1) {
		mall1.clear(); mall2.clear();

		for (int i = 0; i < p1; i++) {
			int r, c;
			cin >> r >> c;
			mall1.push_back({r, c});
		}

		cin >> p2;
		for (int i = 0; i < p2; i++) {
			int r, c;
			cin >> r >> c;
			mall2.push_back({r, c});
		}

		cout << bfs() << '\n';
	}
}
