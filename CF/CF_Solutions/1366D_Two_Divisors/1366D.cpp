#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int	currD1, currD2, n, lowestD[10'000'050], d1[500'050], d2[500'050];

void sieve() {
	for (ll i = 2; i < 1e7; i++) {
		for (ll j = i * i; j <= 1e7; j += i) {
			if (lowestD[j] == -1) lowestD[j] = i;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	memset(lowestD, -1, sizeof lowestD);
	sieve();

	memset(d1, -1, sizeof d1);
	memset(d2, -1, sizeof d2);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (lowestD[a] == -1) continue;
		currD1 = lowestD[a];
		currD2 = a / lowestD[a];
		while (currD2 % currD1 == 0) currD2 /= currD1;
		if (currD2 > 1) {
			d1[i] = currD1;
			d2[i] = currD2;
		}

	}

	for (int i = 0; i < n; i++) cout << d1[i] << " \n"[i == n-1];
	for (int i = 0; i < n; i++) cout << d2[i] << " \n"[i == n-1];
}
