#include <bits/stdc++.h>

using namespace std;

int	tc, n;
bool	a[1050][1050], b[1050][1050], rows[1050], cols[1050];

bool areEqual() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] ^ rows[i] ^ cols[j] != b[i][j]) return 0;
		}
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> n;
	       	cin.ignore();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = (cin.get() == '1');
			}
			cin.ignore();
		}

	       	cin.ignore();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				b[i][j] = (cin.get() == '1');
			}
			cin.ignore();
		}

		memset(rows, 0, sizeof rows);
		memset(cols, 0, sizeof cols);
		for (int i = 0; i < n; i++) if (a[0][i] != b[0][i]) cols[i] = 1;
		for (int i = 1; i < n; i++) if ((a[i][0] == b[i][0]) == cols[0]) rows[i] = 1;

		if (areEqual()) {
			cout << "YES\n";
			continue;
		}

		memset(rows, 0, sizeof rows);
		memset(cols, 0, sizeof cols);
		rows[0] = 1;
		for (int i = 0; i < n; i++) if (a[0][i] == b[0][i]) cols[i] = 1;
		for (int i = 1; i < n; i++) if ((a[i][0] == b[i][0]) == cols[0]) rows[i] = 1;

		if (areEqual()) {
			cout << "YES\n";
			continue;
		}

		cout << "NO\n";
	}
}
