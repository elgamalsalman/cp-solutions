#include<bits/stdc++.h>

using namespace std;

int	ans[2], n, m, a[300'050][10];

bool validate(int minB) {
	map<int, int>	availableMasks;
	for (int bitmask = 0; bitmask < (1 << m); bitmask++) availableMasks[bitmask] = -1;

	for (int i = 0; i < n; i++) {
		int bitmask = 0;
		for (int j = 0; j < m; j++) {
			if (a[i][j] >= minB) bitmask |= (1 << j);
		}
		availableMasks[bitmask] = i;
	}

	for (int bitmask1 = 0; bitmask1 < (1 << m); bitmask1++) {
		if (availableMasks[bitmask1] == -1) continue;
		for (int bitmask2 = 0; bitmask2 < (1 << m); bitmask2++) {
			if (availableMasks[bitmask2] == -1) continue;
			if ((bitmask1 | bitmask2) == (1 << m) - 1) {
				ans[0] = availableMasks[bitmask1];
				ans[1] = availableMasks[bitmask2];
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int l = 0, r = 1e9;
	for (int i = 0; i < 50 && l < r; i++) {
		int mid = (l + r + 1) / 2;
		if (validate(mid)) l = mid;
		else r = mid - 1;
	}

	cout << ans[0] + 1 << ' ' << ans[1] + 1 << '\n';
}
