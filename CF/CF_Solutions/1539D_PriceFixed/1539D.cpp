#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

ll	n, a[100'050], b[100'050], productsCount;
vii	intervals;

ll calcIntervalDistance() {
	sort(intervals.begin(), intervals.end());
	ll i = 0, dis = 0;
	for (ii interval : intervals) {
		if (i < interval.fi) i = interval.fi;
		else if (i > interval.fi) {
			ll diff = i - interval.fi;
			interval.fi += diff;
			interval.se += diff;
		}
		
		if (i >= productsCount) break;
		interval.se = min(interval.se, productsCount - 1);
		dis += interval.se - interval.fi + 1;
		i = interval.se + 1;
	}

	return dis;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

	productsCount = accumulate(a, a + n, 0LL);

	for (int i = 0; i < n; i++) {
		if (b[i] >= productsCount) continue;
		intervals.push_back({b[i], min(b[i] + a[i] - 1, productsCount - 1)});
	}

	ll discounted = calcIntervalDistance();
	cout << (discounted + (productsCount - discounted) * 2) << '\n';
}
