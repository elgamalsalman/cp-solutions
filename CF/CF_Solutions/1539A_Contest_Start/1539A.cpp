#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll	tc, n, x, t, ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> n >> x >> t;
		ll overlap = t / x;
		ll ans = min(overlap, n) / 2.0 * (min(overlap, n) - 1);
		ans += (n - min(overlap, n)) * overlap;

		cout << ans << '\n';
	}
}
