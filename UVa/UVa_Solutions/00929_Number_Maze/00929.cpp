#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define ww fi
#define rr se.fi
#define cc se.se

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;

int	dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0}, dis[1050][1050], maze[1050][1050], tc, N, M;

void dijkstra () {
	memset(dis, -1, sizeof dis);
	dis[0][0] = maze[0][0];
	priority_queue<iii, viii, greater<iii>> pq;

	pq.push({dis[0][0], {0, 0}});
	while (!pq.empty()) {
		iii u = pq.top(); pq.pop();
		if (u.ww > dis[u.rr][u.cc]) continue;
		dis[u.rr][u.cc] = u.ww;
		for (int i = 0; i < 4; i++) {
			int newR = u.rr + dr[i], newC = u.cc + dc[i];
			if (newR < 0 || newR >= N || newC < 0 || newC >= M) continue;
			iii v = {u.ww + maze[newR][newC], {newR, newC}};
			if (dis[v.rr][v.cc] == -1 || dis[v.rr][v.cc] > v.ww) {
				dis[v.rr][v.cc] = v.ww;
				pq.push(v);
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> maze[i][j];
			}
		}

		dijkstra();

		cout << dis[N - 1][M - 1] << '\n';
	}
}
