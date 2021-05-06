#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll	leastConv, currConv, currMem, impNum, regNum, conv, tc, n, m, a[200050], imp[200050], reg[200050];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		leastConv = 1e18;

		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> a[i];
		impNum = regNum = 0;
		for (int i = 0; i < n; i++) {
			cin >> conv;
			if (conv == 1) reg[regNum++] = a[i];
			else imp[impNum++] = a[i];
		}

		sort(imp, imp + impNum, greater<ll>());
		sort(reg, reg + regNum, greater<ll>());

		currMem = accumulate(reg, reg + regNum, 0LL);
		currConv = regNum;
		ll impI = 0, regI = regNum;
		while (impI <= impNum) {
			if (currMem >= m && currConv < leastConv) leastConv = currConv;
			if (currMem > m && regI) {
				currConv--;
				currMem -= reg[--regI];
			} else {
				currConv += 2;
				currMem += imp[impI++];
			}
		}

		cout << (leastConv == 1e18 ? -1 : leastConv) << '\n';
	}
}
