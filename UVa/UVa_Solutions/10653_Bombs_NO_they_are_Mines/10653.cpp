#include <bits/stdc++.h>

using namespace std;

#define rr first
#define cc second

typedef pair<int, int> ii;

int	dc[] = {1, 0, -1, 0}, dr[] = {0, -1, 0, 1}, dis[1005][1005], grid[1005][1005], R, C, rowsWithBombs, bombsNum, bomb, r;
ii	start, dest;

void bfs () {
	queue<ii> q;
	q.push(start);
	
	memset(dis, -1, sizeof dis);
	dis[start.rr][start.cc] = 0;
	while (!q.empty()) {
		ii u = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int newR = u.rr + dr[i], newC = u.cc + dc[i];
			if (newR < 0 || newR >= R || newC < 0 || newC >= C || dis[newR][newC] != -1 || grid[newR][newC] == -1) continue;
			dis[newR][newC] = dis[u.rr][u.cc] + 1;
			q.push({newR, newC});
			
			if (newR == dest.rr && newC == dest.cc) return;
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> R >> C, R || C) {
		memset(grid, 0, sizeof grid);

		cin >> rowsWithBombs;
		for (int i = 0; i < rowsWithBombs; i++) {
			cin >> r >> bombsNum;
			for (int j = 0; j < bombsNum; j++) {
				cin >> bomb;
				grid[r][bomb] = -1;
			}
		}

		cin >> start.rr >> start.cc >> dest.rr >> dest.cc;
		bfs();

		cout << dis[dest.rr][dest.cc] << '\n';
	}
}
