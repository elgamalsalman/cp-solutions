#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll	tc, l, r, num;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> l >> r;
		num = l;
		for (int i = 0;; i++) {
			if (num & (1LL << i)) continue;
			num |= (1LL << i);
			if (num > r) {
				num &= ~(1LL << i);
				break;
			}
		}
		cout << num << '\n';
	}
}
