#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll	k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> k; k--;
	ll totDigits = 0, currInc = 9, digits = 1;
	while (totDigits + currInc <= k) {
		totDigits += currInc;
		digits++;
		currInc = (pow(10, digits) - pow(10, digits - 1)) * digits;
	}

	k -= totDigits;
	ll kSmall = digits - k % digits;
	ll kBig = k / digits;
	cout << (ll)((pow(10, digits - 1) + kBig) / pow(10, kSmall - 1)) % 10 << '\n';
}
