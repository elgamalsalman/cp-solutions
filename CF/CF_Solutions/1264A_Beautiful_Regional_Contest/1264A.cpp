#include<bits/stdc++.h>

using namespace std;

int	tc, g, s, b, n, seq[400000];

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		g = 0; s = 2; b = 4;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> seq[i];
		while (seq[g] <= seq[g + 1] && b < n / 2) {
			g++; s += 2; b += 3;
		}
		while (seq[s] <= seq[s + 1] && b < n / 2) {
			s++; b++;
		}
		int tmpB = b;
		while (tmpB < n / 2) {
			if (seq[tmpB] > seq[tmpB + 1]) b = tmpB;
			tmpB++;
		}
		if (b >= n / 2 || seq[b] <= seq[b + 1]) cout << "0 0 0\n";
		else cout << g + 1 << ' ' << s - g << ' ' << b - s << '\n';
	}
}
