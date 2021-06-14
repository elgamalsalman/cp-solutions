#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int	tc, n, a[10050];
vii	tmpInc;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];

		int sum = accumulate(a, a + n, 0);
		if (sum / (double)n != sum / n) {
			cout << "-1\n";
			continue;
		}
		int targetValue = sum / n;

		cout << 3 * (n - 1) << '\n';
		for (int i = 1; i < n; i++) {
			cout << "1 " << i + 1 << ' ' << (i + 1 - a[i] % (i + 1)) % (i + 1) << '\n';
			cout << i + 1 << " 1 " << ceil(a[i] / (double)(i + 1)) << '\n';
		}

		for (int i = 1; i < n; i++) cout << "1 " << i + 1 << ' ' << targetValue << '\n';
	}
}
