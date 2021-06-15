#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll	mana, a[200050], b[200050], n, m, x, k, y;
bool	valid = 1;
vi	livingInd;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> x >> k >> y; a[0] = a[n + 1] = -1;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	livingInd = {0};
	int bInd = 0;
	for (int i = 1; i <= n && bInd < m; i++) {
		if (a[i] == b[bInd]) {
			livingInd.push_back(i);
			bInd++;
		}
	}
	livingInd.push_back(n + 1);

	if (livingInd.size() < m + 2) valid = 0;

	for (int i = 1; valid && i < m + 2; i++) {
		int dis = livingInd[i] - livingInd[i - 1] - 1;

		bool mustFireBall = 0;
		int maxWarrior = 0;
		for (int j = livingInd[i - 1] + 1; j < livingInd[i]; j++) if (a[j] > maxWarrior) maxWarrior = a[j]; 
		if (maxWarrior > a[livingInd[i - 1]] && maxWarrior > a[livingInd[i]]) mustFireBall = 1;

		if (dis >= k) {
			ll newMana1 = (dis / k) * x + (dis % k) * y;
			ll newMana2 = x + (dis - k) * y;
			ll newMana3 = dis * y;
			mana += min(min(newMana1, newMana2), (mustFireBall ? (ll)1e18 : newMana3));
		} else {
			mana += dis * y;
			if (mustFireBall) valid = 0;
		}
	}

	cout << (valid ? mana : -1) << '\n';
}
