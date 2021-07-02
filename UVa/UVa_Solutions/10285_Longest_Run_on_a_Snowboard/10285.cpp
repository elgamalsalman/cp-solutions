#include <bits/stdc++.h>

using namespace std;

int	maxSlide, dr[] = {1, 0, -1, 0}, dc[] = {0, -1, 0, 1}, dp[105][105], tc, R, C, grid[105][105];
string	name;

int compute(int r, int c) {
	if (r < 0 || c < 0 || r >= R || c >= C) return 0;
	if (dp[r][c]) return dp[r][c];
	dp[r][c] = 1;
	for (int i = 0; i < 4; i++) {
		int newR = r + dr[i], newC = c + dc[i];
		if (grid[r][c] < grid[newR][newC]) dp[r][c] = max(dp[r][c], 1 + compute(newR, newC));
	}

	maxSlide = max(maxSlide, dp[r][c]);
	return dp[r][c];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		maxSlide = 0;

		cin >> name >> R >> C;
		for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) cin >> grid[i][j];

		memset(dp, 0, sizeof dp);
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				compute(i, j);
			}
		}

		cout << name << ": " << maxSlide << '\n';
	}
}
