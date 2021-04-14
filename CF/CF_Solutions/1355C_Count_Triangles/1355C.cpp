#include<bits/stdc++.h>

using namespace std;

#define MAX 1000050

typedef long long ll;

ll	a, b, c, d, ans, s[MAX];

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c >> d;

	ans = 0;
	for (ll i = a; i <= b; i++) {
		s[i + b]++;
		s[i + c + 1]--;
	}
	partial_sum(s, s + MAX, s);
	partial_sum(s, s + MAX, s);

	for (ll i = c; i <= d; i++) {
		ans += s[MAX - 1] - s[i];
	}
	cout << ans << '\n';
}
