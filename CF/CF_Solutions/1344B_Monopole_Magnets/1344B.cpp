#include<bits/stdc++.h>

using namespace std;

int	islandsCount, n, m;
bool	emptyRow, emptyCol, visited[1050][1050], grid[1050][1050], valid = 1;

void dfs(int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= m) return;
	if (grid[i][j] == 0 || visited[i][j]) return;

	visited[i][j] = 1;
	dfs(i, j - 1);
	dfs(i, j + 1);
	dfs(i + 1, j);
	dfs(i - 1, j);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin.ignore();
		for (int j = 0; j < m; j++) {
			grid[i][j] = (cin.get() == '#');
		}
	}

	for (int i = 0; i < n; i++) {
		int l = -1, r = -1;
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 1 && l == -1) l = j;
			else if(grid[i][j] == 0 && l != -1) r = j;
			else if (grid[i][j] == 1 && r != -1) valid = 0;
		}
		if (l == -1) emptyRow = 1;
	}

	for (int j = 0; j < m; j++) {
		int l = -1, r = -1;
		for (int i = 0; i < n; i++) {
			if (grid[i][j] == 1 && l == -1) l = j;
			else if(grid[i][j] == 0 && l != -1) r = j;
			else if (grid[i][j] == 1 && r != -1) valid = 0;
		}
		if (l == -1) emptyCol = 1;
	}

	if (emptyRow ^ emptyCol) valid = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 1 && visited[i][j] == 0) {
				dfs(i, j);
				islandsCount++;
			}
		}
	}

	cout << (valid ? islandsCount : -1) << '\n';
}
