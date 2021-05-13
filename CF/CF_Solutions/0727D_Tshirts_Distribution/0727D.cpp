#include <bits/stdc++.h>

using namespace std;

int	ans[100050], choices[100050], n, quantities[10];

int	sizeToInd(string size) {
	if (size == "S") return 0;
	if (size == "M") return 1;
	if (size == "L") return 2;
	if (size == "XL") return 3;
	if (size == "XXL") return 4;
	if (size == "XXXL") return 5;
}

string	indToSize(int i) {
	switch (i) {
		case 0 : return "S";
		case 1 : return "M";
		case 2 : return "L";
		case 3 : return "XL";
		case 4 : return "XXL";
		case 5 : return "XXXL";
		case -1 : return "-1";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	for (int i = 0; i < 6; i++) cin >> quantities[i];
	cin >> n; cin.ignore();
	for (int i = 0; i < n; i++) {
		string s, size1, size2;
		getline(cin, s);
		stringstream ss(s);
		getline(ss, size1, ',');
		getline(ss, size2, ',');
		choices[i] = (1 << sizeToInd(size1));
		if (!size2.empty()) choices[i] |= (1 << sizeToInd(size2));
		else {
			quantities[sizeToInd(size1)]--;
			ans[i] = sizeToInd(size1);
		}
	}

	for (int currSize = 0; currSize < 6; currSize++) {
		for (int i = 0; i < n; i++) {
			if (__builtin_popcount(choices[i]) == 1) continue;
			if (choices[i] == (1 << currSize) + (1 << (currSize + 1))) {
				if (quantities[currSize] > 0) {
					quantities[currSize]--;
					ans[i] = currSize;
				} else {
					quantities[currSize + 1]--;
					ans[i] = currSize + 1;
				}
			}
		}
	}

	for (int i = 0; i < 6; i++) if (quantities[i] < 0) {
		cout << "NO\n";
		return 0;
	}

	cout << "YES";
	for (int i = 0; i < n; i++) {
		cout << '\n' << indToSize(ans[i]);
	}
	cout << '\n';
}
