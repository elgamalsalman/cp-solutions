#include<bits/stdc++.h> 
using namespace std;

typedef long long ll;

ll	R, G, B, dp[205][205][205], r[205], g[205], b[205];

ll maxArea (int ri, int gi, int bi) {
	ll &currCell = dp[ri][gi][bi];
	if (ri + gi + bi < 2) return currCell = 0;

	if (currCell != -1) return currCell;

	if (ri) currCell = max(currCell, maxArea(ri - 1, gi, bi));
	if (gi) currCell = max(currCell, maxArea(ri, gi - 1, bi));
	if (bi) currCell = max(currCell, maxArea(ri, gi, bi - 1));
	if (ri && gi) currCell = max(currCell, maxArea(ri - 1, gi - 1, bi) + r[ri - 1] * g[gi - 1]);
	if (ri && bi) currCell = max(currCell, maxArea(ri - 1, gi, bi - 1) + r[ri - 1] * b[bi - 1]);
	if (bi && gi) currCell = max(currCell, maxArea(ri, gi - 1, bi - 1) + b[bi - 1] * g[gi - 1]);
	return currCell;
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> G >> B;

	for (int i = 0; i < R; i++) cin >> r[i];
	for (int i = 0; i < G; i++) cin >> g[i];
	for (int i = 0; i < B; i++) cin >> b[i];
	sort(r, r + R);
	sort(g, g + G);
	sort(b, b + B);

	memset(dp, -1, sizeof dp);
	cout << maxArea(R + 1, G + 1, B + 1) << '\n';
}
