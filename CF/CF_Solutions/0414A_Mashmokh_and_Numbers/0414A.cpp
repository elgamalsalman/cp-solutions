#include<bits/stdc++.h>

using namespace std;

int	diff, num, n, k;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	num = k - n/2 + 1;
	if ((n == 1 && k) || num <= 0) {
		cout << "-1\n";
	} else {
		cout << num;

		num *= 2;
		for (int i = 1; i <= n - 1; i++) {
			cout << ' ' << num++;
		} cout << '\n';
	}
}
