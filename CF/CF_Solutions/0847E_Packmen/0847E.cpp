#include <bits/stdc++.h>

using namespace std;

int	n;
char	field[100050];

bool check(int t) {
	int firstStar = -1, advancement = 0;
	for (int i = 0; i < n; i++) {
		if (!advancement && field[i] == '*' && firstStar == -1) firstStar = i;
		if (advancement) advancement--;
		if (field[i] == 'P') {
			int movement = 0;
			if (firstStar != -1) {
				movement = i - firstStar;
				if (movement > t) return 0;
			}
			advancement = max({0, (t - movement) / 2, t - movement * 2});
			firstStar = -1;
		}
	}
	return (firstStar == -1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n; cin.ignore();
	for (int i = 0; i < n; i++) field[i] = cin.get();

	int l = 0, r = n * 2;
	while (l < r) {
		int mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}

	cout << l << '\n';
}
