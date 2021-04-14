#include<bits/stdc++.h>

using namespace std;

string	s;
int	ans, prefixEnd, n, suffixI;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	getline(cin, s);
	n = s.size();

	int i = 0, j = -1, b[1000050];
	b[0] = -1;
	while (i < n) {
		while (j >= 0 && s[i] != s[j]) j = b[j];
		j++; i++;
		b[i] = j;
	}

	ans = 0;
	for (int i = 0; i < n; i++) {
		if (b[i] == b[n]) {
			ans = b[i];
		}
	}

	if (!ans) ans = b[b[n]];
	cout << (ans > 0 ? s.substr(0, ans) : "Just a legend") << '\n';
}
