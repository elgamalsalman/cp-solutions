#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll	a, uniqueNum, n, pre[1000050];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	memset(pre, -1, sizeof pre);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		uniqueNum += (i - pre[a]) * (n - i) * 2 - 1;
		pre[a] = i;
	}

	cout << (double)uniqueNum / (n * n) << '\n'; 
}
