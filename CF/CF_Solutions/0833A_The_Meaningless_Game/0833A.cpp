#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll	a, b, tc;
ld	diff, product, gcd;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> a >> b;
		gcd = __gcd(a, b);
		diff = a * b / (gcd * gcd);
		product = a * b / (diff * diff * diff);
		cout << (cbrt(product) - (int)cbrt(product) ? "No" : "Yes") << '\n';
	}
}
