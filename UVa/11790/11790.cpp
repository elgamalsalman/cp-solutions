#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define height first
#define weight second

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int	tc, n, LISWeight, LDSWeight;
vii	LIS, buildings;
bool	isIncreasing = 1;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	for (int k = 0; k < tc; k++) {
		cin >> n;
		cout << "Case " << k + 1 << ". ";

		buildings.clear();
		for (int i = 0, tmp; i < n; i++) cin >> tmp, buildings.push_back({tmp, 0});
		for (int i = 0; i < n; i++) cin >> buildings[i].weight;

		for (int j = 0; j < 2; j++) {

			LIS.clear();
			for (int i = 0; i < n; i++) {
				auto it1 = lower_bound(LIS.begin(), LIS.end(), buildings[i], [](ii ele1, ii ele2) {
						return (ele1.height > ele2.height);
						});
				int it1Dis = distance(LIS.begin(), it1);
				int totalWeight = (it1 == LIS.begin() ? 0 : (*next(it1, -1)).weight);
				totalWeight += buildings[i].weight;

				auto it2 = upper_bound(LIS.begin(), LIS.end(), totalWeight, [](int val, ii ele2) { 
						return (val <= ele2.weight);
						});
				int it2Dis = distance(LIS.begin(), it2);
				if (it1Dis < it2Dis) fill(it1, it2, make_pair(buildings[i].height, totalWeight));
				LIS.insert(it1, ii(buildings[i].height, totalWeight));
			}
			if (!j) {
				LDSWeight = LIS.back().weight;
				stack<ii> s;
				for (int i = 0; i < n; i++) s.push(buildings[i]);
				buildings.clear();
				for (int i = 0; i < n; i++) {
					buildings.push_back(s.top());
					s.pop();
				}
			} else LISWeight = LIS.back().weight;
		}
		if (LISWeight >= LDSWeight) cout << "Increasing (" << LISWeight << "). Decreasing (" << LDSWeight << ").\n";
		else cout << "Decreasing (" << LDSWeight << "). Increasing (" << LISWeight << ").\n";
	}
}
