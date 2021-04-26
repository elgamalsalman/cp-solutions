#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int	c, tc, d[10000050], ans[10000050];

void sieve() {
	ans[1] = 1;
	for (ll i = 1; i < 1e7; i++) {
		for (ll j = i; j <= 1e7; j += i) d[j] += i;
		if (d[i] <= 1e7 && ans[d[i]] == 0) ans[d[i]] = i;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	sieve();

	cin >> tc;
	while (tc--) {
		cin >> c;
		cout << (ans[c] ? ans[c] : -1) << '\n';
	}
}
