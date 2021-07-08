#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int	qPos[20];
ll	waysCount, dp[20][20];
string	s;

int charToPos(char posChar) {
	if (isalpha(posChar)) return 9 + posChar - 'A';
	else if (isdigit(posChar)) return posChar - '1';
	else return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> s) {
		waysCount = 0;
		memset(dp, 0, sizeof dp);
		for (int i = 0; i < (int) s.size(); i++) qPos[i] = charToPos(s[i]);
		if (qPos[0] == -1) for (int i = 0; i < (int) s.size(); i++) dp[0][i] = 1;
		else dp[0][qPos[0]] = 1;

		for (int i = 0; i < (int) s.size() - 1; i++) {
			for (int j = 0; j < (int) s.size(); j++) {
				if (qPos[i] != -1) j = qPos[i];
				for (int k = 0; k < (int) s.size(); k++) {
					if (abs(j - k) <= 1) continue;
					dp[i + 1][k] += dp[i][j];
				}
				if (qPos[i] != -1) break;
			}
			
		}

		if (qPos[(int) s.size() - 1] == -1) for (int i = 0; i < (int) s.size(); i++) waysCount += dp[(int) s.size() - 1][i];
		else waysCount = dp[(int) s.size() - 1][qPos[(int) s.size() - 1]];

		cout << waysCount << '\n';
	}
}
