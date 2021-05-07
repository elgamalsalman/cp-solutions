#include <bits/stdc++.h>

using namespace std;

#define MODVAL 1000000007

typedef long long ll;

ll	firstOperand, secondOperand, tc, n, x[500050], ans, bits[100];

ll mod(ll x) {return x % MODVAL;}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		ans = 0;
		memset(bits, 0, sizeof bits);

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x[i];
			for (int j = 0; j < 62; j++) if ((1LL << j) & x[i]) bits[j]++;
		}

		for (int i = 0; i < n; i++) {
			firstOperand = secondOperand = 0;
			for (int j = 0; j < 62; j++) {
				if ((1LL << j) & x[i]) firstOperand += mod(bits[j] * mod(1LL << j));
				if ((1LL << j) & x[i]) secondOperand += mod(n * mod(1LL << j));
				else secondOperand += mod(bits[j] * mod(1LL << j));
				firstOperand %= MODVAL;
				secondOperand %= MODVAL;
			}

			ans += mod(firstOperand * secondOperand);
			ans %= MODVAL;
		}

		cout << ans << '\n';
	}
}
