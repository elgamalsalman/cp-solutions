#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef set<int> si;
typedef vector<si> vsi;

int	dp[20][100'050], go[100'050], lastDivisible[100'050], n, q, a[100'050], leastFactor[100'050];
vsi	aFactors;

void sieve() {
	memset(leastFactor, -1, sizeof leastFactor);
	for (ll i = 2; i < 1e5; i++) {
		if (leastFactor[i] != -1) continue;
		for (ll j = i * i; j <= 1e5; j += i) {
			if (leastFactor[j] == -1) leastFactor[j] = i;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	sieve();

	cin >> n >> q;
	aFactors.assign(n, si());
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) {
		int num = a[i];
		while (leastFactor[num] != -1) {
			aFactors[i].insert(leastFactor[num]);
			num /= leastFactor[num];
		}
		if (num != 1) aFactors[i].insert(num);
	}

	fill(lastDivisible, lastDivisible + 100'000, n);
	for (int i = n - 1; i >= 0; i--) {
		int j = n;
		for (int factor : aFactors[i]) {
			j = min(j, lastDivisible[factor]);
			lastDivisible[factor] = i;
		}
		go[i] = j;
	}

	for (int i = n - 1; i > 0; i--) go[i - 1] = min(go[i], go[i - 1]);
	for (int i = 0; i < n; i++) dp[0][i] = go[i];

	dp[0][n] = n;

	for (int i = 1; i < 20; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
		}
	}

	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r; l--; r--;
		
		int steps = 0;
		for (int j = 19; j >= 0; j--) {
			if (dp[j][l] <= r) {
				steps += (1 << j);
				l = dp[j][l];
			}
		}

		cout << steps + 1 << '\n';
	}
}
