#include <bits/stdc++.h>

using namespace std;

int	ans, A[50], B[50], numPossibleAns, a[50], b[50], n, m;

int comp(int i, int j) {
	int numCommons = 0, common;
	if (a[i] == b[j]) {
		numCommons++;
		common = a[i];
	}
	if (a[i + 1] == b[j]) {
		numCommons++;
		common = a[i + 1];
	}
	if (a[i] == b[j + 1]) {
		numCommons++;
		common = a[i];
	}
	if (a[i + 1] == b[j + 1]) {
		numCommons++;
		common = a[i + 1];
	}

	if (numCommons == 1) {
		return common;
	} else return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < 2*n; i++) cin >> a[i];
	for (int i = 0; i < 2*m; i++) cin >> b[i];

	memset(A, 0, sizeof A);
	memset(B, 0, sizeof B);

	bool theirCertainty = 1;
	for (int i = 0; i < 2*n; i+=2) {
		for (int j = 0; j < 2*m; j+=2) {
			int res = comp(i, j);
			if (res > 0) {
				if (ans != res) numPossibleAns++;
				if ((A[i] != res && A[i]) || (B[j] != res && B[j])) theirCertainty = 0;
				A[i] = B[j] = ans = res;
			}
		}
	}

	if (numPossibleAns == 1) cout << ans << '\n';
	else if (theirCertainty) cout << "0\n";
	else cout << "-1\n";
}
