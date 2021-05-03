#include <bits/stdc++.h>

using namespace std;

vector<int> a;
int	g[100050], n, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> g[i];
	sort(g, g + n);

	for (int i = 1; i < n; i++) {
		a.push_back(g[i] - g[i - 1] - 1);
	}
	sort(a.begin(), a.end());

	int ans = n;
	for (int i = 0; i < n - k; i++) {
		ans += a[i];
	}

	cout << ans << '\n';
}
