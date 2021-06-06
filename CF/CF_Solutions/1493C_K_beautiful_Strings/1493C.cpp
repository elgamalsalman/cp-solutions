#include <bits/stdc++.h>

using namespace std;

int	tc, letterCount[50], n, k;
string	s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> tc;
	while(tc--) {
		cin >> n >> k; cin.ignore();
		getline(cin, s);

		memset(letterCount, 0, sizeof letterCount);
		for (char letter : s) letterCount[letter - 'a']++;

		bool isBeautiful = 1;
		for (int i = 0; i < 26; i++) if (letterCount[i] % k) isBeautiful = 0;

		if (isBeautiful) { cout << s << '\n'; continue; }
		if (n % k) { cout << "-1\n"; continue; }

		bool done = 0;
		for (int i = n - 1; i >= 0; i--) {
			letterCount[s[i] - 'a']--;
			for (char letter = s[i] + 1; letter <= 'z'; letterCount[letter - 'a']--, letter++) {
				letterCount[letter - 'a']++;
				int neededLettersCount = 0;
				for (int j = 0; j < 26; j++) neededLettersCount += (k - (letterCount[j] % k)) % k;
				if (neededLettersCount > n - i - 1) continue;
				int extraLettersCount = n - i - 1 - neededLettersCount;
				if (extraLettersCount % k) continue;
				cout << s.substr(0, i) << letter;
				for (int j = 0; j < extraLettersCount; j++) cout << 'a';
				for (int letterInd = 0; letterInd < 26; letterInd++) {
					int t = (k - (letterCount[letterInd] % k)) % k;
					for (int l = 0; l < t; l++) cout << (char)('a' + letterInd);
				}
				cout << '\n';
				done = 1;
				break;
			}

			if (done) break;
		}
	}
}
