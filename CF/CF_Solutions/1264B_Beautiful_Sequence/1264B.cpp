#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int	tmp, tot, diff, digits[4], tmpDigits[4];
vi	v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 4; i++) cin >> digits[i];
	tot = accumulate(digits, digits + 4, 0);
	for (int i = 0; i < 4; i++) {
		if (digits[i] <= 0) continue;
		copy(digits, digits + 4, tmpDigits);
		tmpDigits[i]--;
		v = {i};
		for (int i = 1; i < tot; i++) {
			if ((tmp = v.back() - 1) >= 0 && tmpDigits[tmp]) {
				v.push_back(tmp);
				tmpDigits[tmp]--;
			} else if ((tmp = v.back() + 1) < 4 && tmpDigits[tmp]) {
				v.push_back(tmp);
				tmpDigits[tmp]--;
			} else break;
		}

		if (tot == (int) v.size()) {
			cout << "YES\n";
			for (int i = 0; i < tot; i++) {
				cout << v[i] << " \n"[i == tot - 1];
			}
			return 0;
		}
	}

	cout << "NO\n";
}
