#include<bits/stdc++.h>

using namespace std;

int	maxContSize, currColour, contSize, dc[] = {1, 0, -1, 0}, dr[] = {0, -1, 0, 1}, startR, startC, M, N, world[25][25];
char LAND;

void floodFill (int r, int c, int colour) {
	if (c == -1) c = N - 1;
	else if (c == N) c = 0;
	if (r < 0 || r >= M || world[r][c] != LAND) return;

	world[r][c] = colour; contSize++;
	for (int i = 0; i < 4; i++) {
		floodFill(r + dr[i], c + dc[i], colour);
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	
	while (cin >> M >> N) {
		maxContSize = currColour = 0;
		for (int r = 0; r < M; r++) {
			cin.ignore();
			for (int c = 0; c < N; c++) {
				world[r][c] = cin.get();
			}
		}

		cin >> startR >> startC;

		LAND = world[startR][startC];

		floodFill(startR, startC, 1);
		for (int r = 0; r < M; r++) {
			for (int c = 0; c < N; c++) {
				if (world[r][c] == LAND) {
					contSize = 0;
					floodFill(r, c, ++currColour);
					if (contSize > maxContSize) maxContSize = contSize;
				}
			}
		}

		cout << maxContSize << '\n';
	}
}
