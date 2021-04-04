#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define rr fi.fi
#define cc fi.se
#define dir se

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int	tile, c, ans, dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0}, M, N, grid[55][55], dis[55][55][4];
iii	start, dest;
bool	done;
string	startDir;
queue<iii> bfsQ;

void process (iii u, iii v) {
	if (dis[v.rr][v.cc][v.dir] == -1) {
		dis[v.rr][v.cc][v.dir] = dis[u.rr][u.cc][u.dir] + 1;
		bfsQ.push(v);

		if (v.rr == dest.rr && v.cc == dest.cc) {
			ans = dis[v.rr][v.cc][v.dir];
			done = 1;
		}
	}
}

void bfs () {
	bfsQ = queue<iii>();
	bfsQ.push(start);
	done = 0; ans = -1;

	memset(dis, -1, sizeof dis);
	dis[start.rr][start.cc][start.dir] = 0;
	if (start.rr == dest.rr && start.cc == dest.cc) {
		ans = 0;
		return;
	}

	while (!bfsQ.empty()) {
		iii u = bfsQ.front(); bfsQ.pop();

		for (int i = 1; i < 4; i+=2) {
			iii v = {{u.rr, u.cc}, (u.dir + i) % 4};
			process(u, v);
		}

		for (int i = 1; i <= 3; i++) {
			iii v = {{u.rr + dr[u.dir] * i, u.cc + dc[u.dir] * i}, u.dir};
			if (v.rr < 1 || v.rr >= M || v.cc < 1 || v.cc >= N || grid[v.rr][v.cc] == 1) break;
			process(u, v);
		}

		if (done) return;
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> M >> N, M || N) {
		memset(grid, 0, sizeof grid);
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cin >> tile;
				if (tile == 1) grid[i][j] = grid[i + 1][j] = grid[i][j + 1] = grid[i + 1][j + 1] = 1;
			}
		}

		cin >> start.rr >> start.cc >> dest.rr >> dest.cc >> startDir;
		switch (startDir[0]) {
			case 'e':
				start.dir = 0;
				break;
			case 's':
				start.dir = 1;
				break;
			case 'w':
				start.dir = 2;
				break;
			case 'n':
				start.dir = 3;
				break;
		}

		bfs();

		cout << ans << '\n';
	}
}
