#include <bits/stdc++.h>

using namespace std;

int	tc, n, isFull, moves[200050];
bitset<200050>	pos;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		isFull = 1;
		pos.reset();

		cin >> n;
		for (int i = 0; i < n; i++) cin >> moves[i];
		for (int i = 0; i < n; i++) {
			int currPos = (moves[i] + i) % n;
			if (currPos < 0) currPos += n;
			if (pos[currPos]) isFull = 0;
			else pos[currPos] = 1;
		}
		cout << (isFull ? "YES" : "NO") << '\n';
	}
}
