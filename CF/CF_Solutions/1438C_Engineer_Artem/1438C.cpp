#include <bits/stdc++.h>

using namespace std;

int	tc, n, m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
			int tmp;
			cin >> tmp;
			if ((tmp % 2) != (i + j) % 2) tmp++;
			cout << tmp << " \n"[j == m - 1];
		}
	}
}
