#include<bits/stdc++.h>

using namespace std;

int	dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, tc, n, m;
char	maze[55][55];
bool	valid;

void dfs (int i, int j) {
	if (maze[i][j] == '#' || maze[i][j] == '*' || i < 0 || i >= n || j < 0 || j >= m) return;
	if (maze[i][j] == 'B') {
		valid = 0;
		return;
	}

	maze[i][j] = '*';
	for (int l = 0; l < 4; l++) {
		dfs(i + dy[l], j + dx[l]);
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		valid = 1;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin.ignore();
			for (int j = 0; j < m; j++) {
				cin >> maze[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (maze[i][j] == 'B') {
					for (int k = 0; k < 4; k++) {
						int neighborY = i + dy[k], neighborX = j + dx[k];
						if (neighborY < 0 || neighborY >= n || neighborX < 0 || neighborX >= m) continue;
						
						char &neighbor = maze[neighborY][neighborX];
						if (neighbor == 'G') valid = 0;
						if (neighbor == '.') neighbor = '#';
					}
				}
			}
		}

		dfs(n - 1, m - 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (maze[i][j] == 'G') valid = 0;
			}
		}

		cout << (valid ? "Yes" : "No") << '\n';
	}
}
