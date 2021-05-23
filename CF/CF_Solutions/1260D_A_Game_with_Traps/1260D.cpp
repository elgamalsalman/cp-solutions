#include<bits/stdc++.h>

using namespace std;

#define ll first
#define rr second.first
#define dd second.second

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;

ll	n, m, k, t, a[200050];
iii	tPos[200050];

bool check(ll minA) {
	vector<pair<int, bool>> x;
	for (int i = 0; i < k; i++) {
		if (tPos[i].dd <= minA) continue;
		x.push_back({tPos[i].ll - 1, 0});
		x.push_back({tPos[i].rr, 1});
	}
	sort(x.begin(), x.end());

	int c = 0, res = 0;
	for (int i = 0; i < (int) x.size(); i++) {
		if (c) res += x[i].first - x[i-1].first;
		if (x[i].second) c++;
		else c--;
	}

	ll currT = n + 1 + 2 * res;

	return (currT <= t);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m >> n >> k >> t;

	for (ll i = 0; i < m; i++) cin >> a[i];
	sort(a, a + m);

	for (ll i = 0; i < k; i++) cin >> tPos[i].ll >> tPos[i].rr >> tPos[i].dd;

	ll	l = 0, r = m, mid;
	while (l < r) {
		mid = (l + r) / 2;
		if (check(a[mid])) r = mid;
		else l = mid + 1;
	}

	cout << m - l << '\n';
}
