#include<bits/stdc++.h>

using namespace std;

int	cols[55], grid[55][55], tc, n, m, a, b;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> n >> m >> a >> b;
		
		memset(grid, 0, sizeof grid);
		if (n * a == m * b) {
			cout << "YES\n";

			for (int step = 0; step < m; step++) {
				memset(grid, 0, sizeof grid);
				memset(cols, 0, sizeof cols);
				int startingInd = 0;
				for (int i = 0; i < n; i++) {
					for (int j = startingInd; j < startingInd + a; j++) {
						grid[i][j % m] = 1;
						cols[j % m]++;
					}
					startingInd += step;
				}
				bool valid = 1;
				for (int i = 0; i < m; i++) if (cols[i] != b) valid = 0;
				if (valid) {
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++) {
							cout << grid[i][j];
						}
						cout << '\n';
					}
					break;
				}
			}

		} else cout << "NO\n";
	}
}
