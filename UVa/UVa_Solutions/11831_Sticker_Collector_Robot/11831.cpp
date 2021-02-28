#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define y first
#define x second

typedef pair<int, int> ii;

int	dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
int	stickers, dir, N, M, S;
ii	pos;
char	grid[105][105];

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> N >> M >> S, N && M && S) {
		stickers = 0;
		for (int i = 0; i < N; i++) {
			cin.ignore();
			for (int j = 0; j < M; j++) {
				char cell = cin.get();
				if (cell != '.' && cell != '#' && cell != '*') {
					pos.x = j; pos.y = i;
					if (cell == 'N') dir = 0;
					if (cell == 'L') dir = 1;
					if (cell == 'S') dir = 2;
					if (cell == 'O') dir = 3;
					cell = '.';
				}
				grid[i][j] = cell;
			}
		}

		cin.ignore();
		for (int i = 0; i < S; i++) {
			char instruction = cin.get();
			if (instruction == 'D') dir++;
			if (instruction == 'E') dir--;
			dir = (dir + 4) % 4;
			if (instruction == 'F') {
				ii newPos = {pos.y + dy[dir], pos.x + dx[dir]};
				newPos.x = max(newPos.x, 0);
				newPos.y = max(newPos.y, 0);
				newPos.x = min(newPos.x, M - 1);
				newPos.y = min(newPos.y, N - 1);

				if (grid[newPos.y][newPos.x] != '#') {
					if (grid[newPos.y][newPos.x] == '*') stickers++, grid[newPos.y][newPos.x] = '.';
					pos = newPos;
				}
			}
		}
		cout << stickers << '\n';
	}
}
