#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll	n, m, k;

ll f (ll val) {
	ll res = 0;
	for (int i = 1; i <= m; i++) {
		res += min(n, (val - 1)/i);
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	ll l = 1, r = m * n;
	for (int i = 0; i < 45; i++) {
		ll val = (l + r + 1) / 2;
		ll res = f(val);
		if (res < k) l = val;
		else r = val - 1;
	}

	cout << l << '\n';
}
