#include <bits/stdc++.h>

using namespace std;

int	prevX, prevT, dest, currLoc, finalLoc, succNum, tc, n, t, x;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> n;
		currLoc = finalLoc = succNum = dest = prevT = prevX = 0;
		for (int i = 0; i < n; i++) {
			cin >> t >> x;
			if (t - prevT >= abs(dest - currLoc)) finalLoc = dest;
			else if (dest > currLoc) finalLoc = currLoc + (t - prevT);
			else finalLoc = currLoc - (t - prevT);

			if (i && ((prevX >= currLoc && prevX <= finalLoc) || (prevX <= currLoc && prevX >= finalLoc))) succNum++;

			if (finalLoc == dest) dest = x;

			prevX = x;
			prevT = t;
			currLoc = finalLoc;
		}
		if ((prevX >= currLoc && prevX <= dest) || (prevX <= currLoc && prevX >= dest)) succNum++;

		cout << succNum << '\n';
	}
}
