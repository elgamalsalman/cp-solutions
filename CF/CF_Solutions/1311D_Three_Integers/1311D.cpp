#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int	ans[3], minDiff = 1e9, tc, a, b, c;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		minDiff = 1e9;

		cin >> a >> b >> c;
		for (int i = 1; i <= 2 * a; i++) {
			for (int j = i; j <= 2 * b; j += i) {
				int d = c / j;
				int k = d * j;
				int currDiff = abs(a - i) + abs(b - j) + abs(c - k);
				if (minDiff > currDiff) {
					minDiff = currDiff;
					ans[0] = i;
					ans[1] = j;
					ans[2] = k;
				}

				k += j;
				currDiff = abs(a - i) + abs(b - j) + abs(c - k);
				if (minDiff > currDiff) {
					minDiff = currDiff;
					ans[0] = i;
					ans[1] = j;
					ans[2] = k;
				}
			}
		}

		cout << minDiff << '\n';
		for (int i = 0; i < 3; i++) cout << ans[i] << " \n"[i == 2];
	}
}
