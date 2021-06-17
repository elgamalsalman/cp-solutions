#include<bits/stdc++.h>

using namespace std;

int	tc, n, k, a[100'050];
string	s;

void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }

bool sFind(string pattern) {
	for (int i = 0; i < n - pattern.size() + 1; i++) {
		bool found = 1;
		for (int j = 0; j < pattern.size(); j++) {
			if (s[i + j] != pattern[j]) found = 0;
		}
		if (found) return 1;
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		s = "";

		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			if (tmp == k) s += '1';
			else if (tmp < k) s += '0';
			else if (tmp > k) s += '2';
		}

		if (s.find("1") == -1) { no(); continue; }
		if (s.size() == 1 || sFind("11") || sFind("101") || sFind("22") || sFind("202") || sFind("12") || sFind("21") || sFind("102") || sFind("201")) { yes(); continue; }
		no();
	}
}
