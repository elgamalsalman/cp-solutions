#include<bits/stdc++.h>

using namespace std;

int	tcNum, dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1}, ships, tc, N;
char	grid[105][105];

void floodFill (int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= N || grid[x][y] == '.') return;
	grid[x][y] = '.';
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (grid[nextX][nextY] == 'x' || grid[nextX][nextY] == '@') {
			floodFill(nextX, nextY);
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		ships = 0;

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin.ignore();
			for (int j = 0; j < N; j++) {
				grid[i][j] = cin.get();
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (grid[i][j] == 'x') {
					floodFill(i, j);
					ships++;
				}
			}
		}

		cout << "Case " << ++tcNum << ": " << ships << '\n';
	}
}
