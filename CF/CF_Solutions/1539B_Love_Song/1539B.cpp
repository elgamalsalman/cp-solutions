#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int	n, q, a[100'050];
string	s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q; cin.ignore();
	getline(cin, s);
	for (int i = 0; i < n; i++) a[i] = s[i] - 'a' + 1;
	partial_sum(a, a + n, a);

	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		int ans = a[r - 1];
		if (l != 1) ans -= a[l - 2];
		cout << ans << '\n';
	}
}
