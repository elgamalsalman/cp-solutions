#include <bits/stdc++.h>

using namespace std;

int	tc, n;
string	s[3];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> n; cin.ignore();
		for (int i = 0; i < 3; i++) getline(cin, s[i]);

		vector<string> halfZeros, halfOnes;
		for (int i = 0; i < 3; i++) {
			int zeros = 0, ones = 0;
			for (char bit : s[i]) {
				if (bit == '0') zeros++;
				else ones++;
			}

			if (zeros >= n) halfZeros.push_back(s[i]);
			if (ones >= n) halfOnes.push_back(s[i]);
		}

		if ((int) halfZeros.size() > 1) {
			int i = 0, j = 0;
			while (i < 2 * n || j < 2 * n) {
				if (i < 2 * n && halfZeros[0][i] == '1') {
					cout << 1;
					i++;
				} else if (j < 2 * n && halfZeros[1][j] == '1') {
					cout << 1;
					j++;
				} else {
					cout << 0;
					i++; j++;
				}
			}
		} else {
			int i = 0, j = 0;
			while (i < 2 * n || j < 2 * n) {
				if (i < 2 * n && halfOnes[0][i] == '0') {
					cout << 0;
					i++;
				} else if (j < 2 * n && halfOnes[1][j] == '0') {
					cout << 0;
					j++;
				} else {
					cout << 1;
					i++; j++;
				}
			}
		}
		
		cout << '\n';
	}
}
