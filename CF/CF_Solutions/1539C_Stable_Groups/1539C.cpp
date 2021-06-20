#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

ll	n, k, x, a[200'050];
vi	gaps;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> x;
	for (ll i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);

	ll groupCount = 1;
	for (ll i = 1; i < n; i++) {
		if (a[i] - a[i - 1] > x) gaps.push_back((a[i] - a[i - 1] - 1) / x);
	}
	sort(gaps.begin(), gaps.end());

	ll groups = gaps.size() + 1;
	for (ll i = 0; i < gaps.size(); i++) {
		if (k < gaps[i]) break;
		k -= gaps[i];
		groups--;
	}

	cout << groups << '\n';
}
