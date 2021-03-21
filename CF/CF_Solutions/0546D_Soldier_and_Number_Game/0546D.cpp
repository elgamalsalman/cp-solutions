#include<bits/stdc++.h>

using namespace std;

#define MAX 5000050

int	tc, a, b, maxScore, leastFactors[MAX], pFactors[MAX];

void sieve () {
	for (int j = 2; j < MAX; j++) {
		if (leastFactors[j]) continue;
		for (int i = j * 2; i < MAX; i += j) {
			if (!leastFactors[i]) leastFactors[i] = j;
		}
	}
}

int countPFactors (int num) {
	if (!leastFactors[num]) return pFactors[num] = 1;
	if (pFactors[num]) return pFactors[num];
	return pFactors[num] = pFactors[num / leastFactors[num]] + 1;
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	sieve();
	for (int i = 2; i < MAX; i++) if(!pFactors[i]) countPFactors(i);

	partial_sum(pFactors, pFactors + MAX, pFactors);

	cin >> tc;
	while (tc--) {
		cin >> a >> b;
		cout << pFactors[a] - pFactors[b] << '\n';
	}
}
