#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll	n, k, tc, a[100050];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		ll perm = k - 1;
		for (ll i = 0; i < n; i++) {
			a[i] = i + 1;
		}
		ll pre = n - 1;
		for (ll i = 0; (1LL << i) <= k * 2 && i < n; i++) {
			if (!(perm & (1LL << i))) {
				reverse(a + n - i - 1, a + pre + 1);
				pre = n - i - 2;
			}
		}

		if (n < 64 && perm > (1LL << (n - 1)) - 1) cout << "-1\n";
		else {
			for (ll i = 0; i < n; i++) {
				if (i) cout << ' ';
				cout << a[i];
			}
			cout << '\n';
		}
	}
}
