#include<bits/stdc++.h>

using namespace std;

#define MODVAL 998244353

typedef long long ll;
typedef map<int, int> mii;

int	r, n, a[200050];
ll	ans = 1;
mii	lastOcc;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		lastOcc[a[i]] = i;
	}

	for (int i = 0; i < n; i++) {
		if (i > r) {
			ans *= 2;
			ans %= MODVAL;
		}

		if (lastOcc[a[i]] > r) r = lastOcc[a[i]];
	}

	cout << ans << '\n';
}
