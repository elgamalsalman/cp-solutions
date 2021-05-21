#include<bits/stdc++.h>

using namespace std;

int	tc, n, a[40];

int MSOne(int num) {
	return (32 - __builtin_clz(num));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		memset(a, 0, sizeof a);

		cin >> n;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			for (int i = 0; i < 32; i++) if (tmp & (1 << i)) a[i]++;
		}

		bool isDraw = 1;
		for (int i = 31; i >= 0; i--) {
			if (a[i] % 4 == 1) {
				isDraw = 0;
				cout << "WIN\n";
				break;
			} else if (a[i] % 4 == 3) {
				cout << ((n - a[i]) % 2 ? "WIN" : "LOSE") << '\n';
				isDraw = 0;
				break;
			}
		}

		if (isDraw) cout << "DRAW\n";
	}
}
