#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int	tc, n;
map<int, ii>	eleRanges;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		eleRanges.clear();

		cin >> n;
		for (int i = 1; i <= n; i++) {
			int tmp;
			cin >> tmp;
			if (eleRanges[tmp].fi == 0) eleRanges[tmp] = {i, i};
			else eleRanges[tmp].se = i;
		}

		int maxSeqLen = 0, currSeqLen = 0;
		iii prevRange = {0, {0, 0}};
		for (iii currEleRange : eleRanges) {
			if (prevRange.se.se < currEleRange.se.fi) currSeqLen++;
			else currSeqLen = 1;
			maxSeqLen = max(maxSeqLen, currSeqLen);
			prevRange = currEleRange;
		}

		cout << eleRanges.size() - maxSeqLen << '\n';
	}
}
