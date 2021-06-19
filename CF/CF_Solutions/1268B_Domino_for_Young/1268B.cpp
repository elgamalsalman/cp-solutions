#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll	n, blacks, whites;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		blacks += tmp / 2;
		whites += tmp / 2;
		if (tmp % 2) {
			if (i % 2) blacks++;
			else whites++;
		}
	}

	cout << min(whites, blacks) << '\n';
}
