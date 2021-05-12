#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int	ind, n, a[100050];
vvi	uniEles;
map<int, int>	m;

bool	swapCheck(int i1, int i2) {
	bool isNonDec = 1, isNonInc = 1;
	int pre = 0, currI;
	for (int i = 0; i < n; i++) {
		currI = i;
		if (i == i1) currI = i2;
		else if (i == i2) currI = i1;

		if (i && pre < a[currI]) isNonInc = 0;
		if (i && pre > a[currI]) isNonDec = 0;

		pre = a[currI];
	}

	return !(isNonDec || isNonInc);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (m[a[i]]) {
			uniEles[m[a[i]] - 1].push_back(i);
		} else {
			m[a[i]] = ++ind;
			uniEles.push_back({i});
		}
	}

	int checks = 0;
	for (int i = 0; i < (int) uniEles.size(); i++) {
		for (int I = 0; I < (int) uniEles[i].size(); I++) {
			for (int j = i + 1; j < (int) uniEles.size(); j++) {
				for (int J = 0; J < (int) uniEles[j].size(); J++) {
					checks++;
					if (swapCheck(uniEles[i][I], uniEles[j][J])) {
						cout << uniEles[i][I] + 1 << ' ' << uniEles[j][J] + 1 << '\n';
						return 0;
					}
					if (checks > 2) {
						cout << -1;
						return 0;
					}
				}
			}
		}
	}

	cout << -1 << '\n';
}
