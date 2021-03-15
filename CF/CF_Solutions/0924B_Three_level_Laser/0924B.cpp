#include <bits/stdc++.h>

using namespace std;

int	n, U, E[100050];
long double	maxEff;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> U;
	for (int i = 0; i < n; i++) cin >> E[i];
	for (int i = 0, k = 2; i < n - 2;) {
		if (E[k] - E[i] <= U) maxEff = max(maxEff, ((long double) E[k] - E[i + 1]) / (E[k] - E[i]));

		if (k < n - 1 && E[k + 1] - E[i] <= U) k++;
		else i++;
		if (k - i < 2) k++;
	}
	cout << fixed << setprecision(10) << (maxEff ? maxEff : -1) << '\n';
}
