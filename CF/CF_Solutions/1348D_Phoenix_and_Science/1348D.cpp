#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int	tc, n;
vi	v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> n;
		v = {1};
		int sum = 1;
		while (sum <= n) {
			v.push_back(v.back() * 2);
			sum += v.back();
		} 
		sum -= v.back();
		v.pop_back();
		
		if (sum != n) v.push_back(n - sum);
		sort(v.begin(), v.end());

		cout << (int) v.size() - 1 << '\n';
		for (int i = 1; i < (int) v.size(); i++) {
			cout << (i == 1 ? "" : " ") << v[i] - v[i - 1];
		}
		cout << '\n';
	}
}
