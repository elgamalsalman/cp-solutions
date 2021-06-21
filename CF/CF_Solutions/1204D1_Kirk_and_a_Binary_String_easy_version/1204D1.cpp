#include <bits/stdc++.h>

using namespace std;

int	n;
string	s;

int lis(int l, int r) {
	vector<int> sublis;
	for (int i = l; i <= r; i++) {
		if (s[i] == '1') {
			sublis.push_back(1);
		} else {
			auto it = upper_bound(sublis.begin(), sublis.end(), 0);
			if (it == sublis.end()) sublis.push_back(0);
			else *it = 0;
		}	
	}

	return sublis.size();
}

int main() {
	getline(cin, s);

	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') continue;
		int lisLen1 = lis(i, n - 1);
		s[i] = '0';
		int lisLen2 = lis(i, n - 1);
		if (lisLen1 != lisLen2) s[i] = '1';
	}

	cout << s << '\n';
}
