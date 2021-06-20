#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

int	n;
string	s;
pair<int, int>	swappedInd;

int countValidRotations(string s) {
	int closingCount = 0, openingCount = 0, validRotCount = 0;
	for (int i = 0; i < (int) s.size(); i++) {
		if (s[i] == '(') openingCount++;
		else closingCount++;

		if (closingCount > openingCount) {
			openingCount = closingCount = 0;
			validRotCount = 1;
		} else if (closingCount == openingCount) validRotCount++;
	}

	return validRotCount;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n; cin.ignore();
	getline(cin, s);

	int openingCount = 0, closingCount = 0;
	for (int i = 0; i < (int) s.size(); i++) if (s[i] == '(') openingCount++; else closingCount++;
	if (openingCount != closingCount) {
		cout << "0\n1 1\n";
		return 0;
	}

	int maxRot = countValidRotations(s);
	swappedInd = {1, 1};
	for (int i = 0; i < (int) s.size(); i++) {
		for (int j = i + 1; j < (int) s.size(); j++) {
			if (s[i] == s[j]) continue;
			string swappedS = s;

			if (swappedS[i] == '(') swappedS[i] = ')';
			else swappedS[i] = '(';
			if (swappedS[j] == '(') swappedS[j] = ')';
			else swappedS[j] = '(';
			
			int currRot = countValidRotations(swappedS);
			if (currRot > maxRot) {
				maxRot = currRot;
				swappedInd = {i + 1, j + 1};
			}
		}
	}

	cout << maxRot << '\n';
	cout << swappedInd.fi << ' ' << swappedInd.se << '\n';
}
