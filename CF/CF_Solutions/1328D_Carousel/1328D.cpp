#include<bits/stdc++.h>

using namespace std;

int	tc, n, a[200050];
bool	areSame, areDiff;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> n;
		areDiff = 1;
		areSame = 1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i && a[i] == a[i - 1]) areDiff = 0;
			else if (i) areSame = 0;
		}
		if (a[0] == a[n - 1]) areDiff = 0;
		if (!areSame && n % 2 == 0) {
			cout << "2\n1";
			for (int i = 1; i < n; i++) {
				cout << ' ' << (i % 2 ? 2 : 1);
			}
			cout << '\n';

		} else if (!areSame) {
			if (areDiff) cout << "3\n1";
			else cout << "2\n1";
			bool switched = 0, colour = 0;
			for (int i = 1; i < n - 1; i++) {
				if (!switched && a[i] == a[i - 1]) {
					colour = !colour;
					switched = 1;
				}
				cout << ' ' << (colour ? 1 : 2);
				colour = !colour;
			}
			if (!areDiff && !switched && a[n - 1] == a[n - 2]) cout << ' ' << (colour ? 2 : 1) << '\n';
			else if (!areDiff) cout << ' ' << (colour ? 1 : 2) << '\n';
			else cout << " 3\n";

		} else {
			cout << "1\n";
			for (int i = 0; i < n; i++) cout << (i ? " " : "") << 1;
			cout << '\n';
		}
	}
}
