#include<bits/stdc++.h>

using namespace std;

#define MODVAL 1000000007

typedef long long ll;

ll	ans, pre, curr, n, m;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	pre = 1; curr = 1;
	for (int i = 1; i < n; i++) {
		ll tmp = curr;
		curr += pre;
		pre = tmp;
		curr %= MODVAL;
	}
	ans = curr;

	pre = 1; curr = 1;
	for (int i = 1; i < m; i++) {
		ll tmp = curr;
		curr += pre;
		pre = tmp;
		curr %= MODVAL;
	}
	ans += curr; ans--; ans *= 2;
	ans %= MODVAL;

	cout << ans << '\n';
}
