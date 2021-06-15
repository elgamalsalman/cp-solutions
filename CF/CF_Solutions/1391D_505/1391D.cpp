#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll	a[1000050], dp[1000050][15], minChanges = 1e9, dim, n, m;
string	s[1000050];

int	trans[][2] = {
	{1, 2},
	{0, 3},
	{0, 3},
	{1, 2},
	{9, 6},
	{7, 8},
	{4, 11},
	{5, 10},
	{10, 5},
	{11, 4},
	{7, 8},
	{9, 6}
};

map<string, int> intLookup = {
	{"00", 0},
	{"01", 1},
	{"10", 2},
	{"11", 3},
	{"000", 4},
	{"001", 5},
	{"010", 6},
	{"011", 7},
	{"100", 8},
	{"101", 9},
	{"110", 10},
	{"111", 11}
};

map<int, string> stringLookup = {
	{0, "00"},
	{1, "01"},
	{2, "10"},
	{3, "11"},
	{4, "000"},
	{5, "001"},
	{6, "010"},
	{7, "011"},
	{8, "100"},
	{9, "101"},
	{10, "110"},
	{11, "111"}
};

int countDiff(string s1, string s2) {
	if (s1.size() != s2.size()) return -1;
	int diffCount = 0;
	for (int i = 0; i < s1.size(); i++) if (s1[i] != s2[i]) diffCount++;
	return diffCount;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m; cin.ignore();
	dim = min(n, m);
	if (n > 3 && m > 3) {
		cout << "-1\n";
		return 0;
	} else if (n == 1 || m == 1) {
		cout << "0\n";
		return 0;
	}

	if (n > 3) {
		for (int i = 0; i < n; i++) {
			getline(cin, s[i]);
			a[i] = intLookup[s[i]];
		}
		dim = n;
	} else {
		for (int i = 0; i < n; i++) {
			string tmp;
			getline(cin, tmp);
			for (int j = 0; j < tmp.size(); j++) {
				s[j] += tmp[j];
			}
		}

		for (int i = 0; i < m; i++) a[i] = intLookup[s[i]];
		dim = m;
	}

	memset(dp, -1, sizeof dp);
	for (int i = 0; i < 12; i++) dp[0][i] = countDiff(s[0], stringLookup[i]);

	for (int i = 0; i < dim; i++) {
		for (int c = 0; c < 12; c++) {
			if (dp[i][c] == -1) continue;
			for (int j = 0; j < 2; j++) {
				ll nextC = trans[c][j], diff = countDiff(stringLookup[nextC], s[i + 1]);
				if (diff == -1) continue;
				if (dp[i + 1][nextC] == -1 || dp[i + 1][nextC] > dp[i][c] + diff) dp[i + 1][nextC] = dp[i][c] + diff;
			}
		}
	}

	for (int c = 0; c < 12; c++) if (dp[dim - 1][c] != -1) minChanges = min(minChanges, dp[dim - 1][c]);

	cout << (minChanges == 1e9 ? -1 : minChanges) << '\n';
}
