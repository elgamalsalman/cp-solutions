#include <bits/stdc++.h>

using namespace std;

#define MODVAL 1000000007

typedef long long ll;

ll	N, ans, layerNum, fact[2000050];

ll binExp(ll base, ll exp) {
	if (exp == 0) return 1;
	ll res = binExp(base, exp/2);
	res = res * res % MODVAL;
	if (exp % 2) res *= base;
	return res % MODVAL;
}

ll C(ll n, ll r) {
	return fact[n] * binExp(fact[r] * fact[n - r] % MODVAL, MODVAL - 2) % MODVAL;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	ans = 2; layerNum = 2;
	for (int i = 0; i < N; i++) {
		ans = (ans * 2) % MODVAL;
		if (i == N - 2) layerNum = ans;
	}
	ans--; if (ans < 0) ans += MODVAL;

	fact[0] = 1;
	for (int i = 1; i <= 2e6; i++) {
		fact[i] = fact[i - 1] * i % MODVAL;
	}

	for (int i = 0; i < N; i++) {
		layerNum = (layerNum * 2 % MODVAL - C(N + i, N) * 2 % MODVAL) % MODVAL;
		if (layerNum < 0) layerNum += MODVAL;
		ans = (ans + layerNum) % MODVAL;
	}

	cout << ans << '\n';
}
