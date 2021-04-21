#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

ll	n, k, a[100050], b[100050];
vii	res;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}

	sort(b, b + n);

	for (int i = n - 1; i > 0; i--) {
		b[i] -= b[i - 1];
	}

	ll rotations = 0;
	for (int i = 0; i < n; i++) {
		ll maxKDiff = b[i] * (n - i);
		if (maxKDiff > k) {
			rotations += k / (n - i);
			k %= (n - i);
			break;
		} else k -= maxKDiff;
		rotations += b[i];
	}

	res.clear();
	for (int i = 0; i < n; i++) {
		if (a[i] > rotations) res.push_back({a[i] - rotations, i});
	}

	if (k > (int) res.size()) {
		cout << "-1\n";
		return 0;
	}

	for (int i = 0; i < k; i++) {
		res[i].fi--;
		if (res[i].fi <= 0) {
			res.erase(res.begin() + i); k--; i--;
		}
	}

	rotate(res.begin(), res.begin() + k, res.end());

	for (int i = 0; i < (int) res.size(); i++) {
		if (i) cout << ' ';
		cout << res[i].se + 1;
	}
	cout << '\n';
}
