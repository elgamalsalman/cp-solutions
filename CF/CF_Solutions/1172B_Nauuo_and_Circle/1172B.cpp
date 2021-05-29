#include <bits/stdc++.h>

using namespace std;

#define MODVAL 998244353

typedef long long ll;

ll	n, fact[200050], degrees[200050], ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fact[0] = fact[1] = 1;
	for (int i = 2; i < 200010; i++) fact[i] = (fact[i - 1] * i) % MODVAL;

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		degrees[u]++;
		degrees[v]++;
	}

	ans = n;
	for (int i = 1; i <= n; i++) {
		int d = degrees[i];
		ans = (ans * fact[d]) % MODVAL;
	}
	
	cout << ans << '\n';
}
