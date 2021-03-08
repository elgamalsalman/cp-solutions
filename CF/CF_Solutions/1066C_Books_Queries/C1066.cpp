#include<bits/stdc++.h>

using namespace std;

int	pos[200050], l, r, qID, q;
char	qChar;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> q >> qChar >> qID;
	while (--q) {
		cin >> qChar >> qID;
		if (qChar == 'L') {
			l++;
			pos[qID] = -l;
		}
		if (qChar == 'R') {
			r++;
			pos[qID] = r;
		}
		if (qChar == '?') {
			cout << min(l + pos[qID], r - pos[qID]) << '\n';
		}
	}
}
