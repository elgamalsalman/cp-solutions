#include <bits/stdc++.h>

using namespace std;

#define MODVAL 998244353

typedef long long ll;

ll	n, m, k, ans;

ll binExp(ll base, ll exponent) {
	if (!exponent) return 1;
	ll tmp = binExp(base, exponent / 2);
	tmp = tmp * tmp % MODVAL;
	if (exponent % 2) tmp = tmp * base % MODVAL;
	return tmp;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	if (n == 1) ans = binExp(k, m);
	else if (m == 1) ans = binExp(k, n);
	else for (ll i = 1; i <= k; i++) ans = (ans + ((binExp(i, n) - binExp(i - 1, n) + MODVAL) * binExp(k - i + 1, m))) % MODVAL;

	cout << ans << '\n';
}
