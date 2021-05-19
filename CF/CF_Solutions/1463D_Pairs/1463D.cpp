#include<bits/stdc++.h>

using namespace std;

int	numA, numB, maxX1, maxX2, tc, n;
bitset<500050>	isInB;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		isInB.reset();
		maxX1 = maxX2 = 0;

		cin >> n;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			isInB[tmp] = 1;
		}

		numB = 0, numA = 0;
		for (int i = 1; i <= 2 * n; i++) {
			if (isInB[i]) numB++;
			else numA++;
			if (numB - numA > maxX1) maxX1 = numB - numA;
		}

		numB = 0, numA = 0;
		for (int i = 2 * n; i > 0; i--) {
			if (isInB[i]) numB++;
			else numA++;
			if (numB - numA > maxX2) maxX2 = numB - numA;
		}
		
		cout << 1 + n - maxX2 - maxX1 << '\n';
	}
}
