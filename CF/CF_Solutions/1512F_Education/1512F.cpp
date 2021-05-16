#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll	minDays, tc, n, c, a[200050], b[200050];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		minDays = 1e9;

		cin >> n >> c;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n - 1; i++) cin >> b[i];

		ll currMoney = 0, currDays = 0;
		for (int i = 0; i < n; i++, currDays++) {
			ll finalDays = currDays + ceil(max(0LL, c - currMoney) / (double) a[i]);
			if (minDays > finalDays) minDays = finalDays;
			
			if (i == n - 1) break;
			ll extraDays = ceil(max(0LL, b[i] - currMoney) / (double) a[i]);
			currDays += extraDays;
			currMoney += extraDays * a[i] - b[i];
		}

		cout << minDays << '\n';
	}
}
