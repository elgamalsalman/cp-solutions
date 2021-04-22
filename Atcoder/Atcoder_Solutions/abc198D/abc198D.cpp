#include <bits/stdc++.h>

using namespace std;

int	digits[50], n1, n2, n3;
string	s1, s2, s3;
vector<char>	letters;

bool isValid() {
	int carry = 0;
	for (int i = 0; i < (int) s3.size(); i++) {
		int res = carry;
		if (i < (int) s1.size()) res += digits[s1[i] - 'a'];
		if (i < (int) s2.size()) res += digits[s2[i] - 'a'];
		carry = res / 10;
		res %= 10;

		if (digits[s3[i] - 'a'] != res) return 0;
	}

	if (carry || !digits[s1.back() - 'a'] || !digits[s2.back() - 'a'] || !digits[s3.back() - 'a']) return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s1 >> s2 >> s3;
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	reverse(s3.begin(), s3.end());

	for (char letter : s1) if (find(letters.begin(), letters.end(), letter) == letters.end()) letters.push_back(letter);
	for (char letter : s2) if (find(letters.begin(), letters.end(), letter) == letters.end()) letters.push_back(letter);
	for (char letter : s3) if (find(letters.begin(), letters.end(), letter) == letters.end()) letters.push_back(letter);

	if (letters.size() > 10) {
		cout << "UNSOLVABLE\n";
		return 0;
	} else letters.resize(10, '~');

	sort(letters.begin(), letters.end());

	do {
		for (int i = 0; i < (int) letters.size(); i++) digits[letters[i] - 'a'] = i;
		if (isValid()) {
			reverse(s1.begin(), s1.end());
			reverse(s2.begin(), s2.end());
			reverse(s3.begin(), s3.end());

			for (char letter : s1) cout << digits[letter - 'a']; 
			cout << '\n';
			for (char letter : s2) cout << digits[letter - 'a']; 
			cout << '\n';
			for (char letter : s3) cout << digits[letter - 'a']; 
			cout << '\n';
			return 0;
		}
	} while (next_permutation(letters.begin(), letters.end()));

	cout << "UNSOLVABLE\n";
}
