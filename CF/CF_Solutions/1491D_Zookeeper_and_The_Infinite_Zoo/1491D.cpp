#include <bits/stdc++.h>

using namespace std;

int	q, u, v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> q;
	while (q--) {
		cin >> u >> v;

		bool isValid = 1;
		if (__builtin_popcount(v) > __builtin_popcount(u)) isValid = 0;
		if (u > v) isValid = 0;

		while (u && v) {
			int LSOneU = u & -u, LSOneV = v & -v;
			if (LSOneU > LSOneV) isValid = 0;
			u -= LSOneU;
			v -= LSOneV;
		}

		if (isValid) cout << "YES\n";
		else cout << "NO\n";
	}
}
