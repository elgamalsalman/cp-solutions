#include<bits/stdc++.h>

using namespace std;

int	n, toffee[1050];
char	letters[1050];

void dfs(int i) {
	if (i && letters[i - 1] == 'L' && toffee[i - 1] < toffee[i] + 1) {
		toffee[i - 1] = toffee[i] + 1;
		dfs(i - 1);
	} 
	if (i < n - 1 && letters[i] == 'R' && toffee[i + 1] < toffee[i] + 1) {
		toffee[i + 1] = toffee[i] + 1;
		dfs(i + 1);
	}
	if (i && letters[i - 1] == '=' && toffee[i - 1] != toffee[i] + 1) {
		toffee[i - 1] = toffee[i] = max(toffee[i - 1], toffee[i]);
		dfs(i - 1);
	} 
	if (i < n - 1 && letters[i] == '=' && toffee[i + 1] != toffee[i]) {
		toffee[i + 1] = toffee[i] = max(toffee[i + 1], toffee[i]);
		dfs(i + 1);
	}
}

bool isBottom(int i) {
	if (i && letters[i - 1] == 'R') return 0;
	if (i < n - 1 && letters[i] == 'L') return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n; cin.ignore();
	for (int i = 0; i < n - 1; i++) {
		letters[i] = cin.get();
	}

	fill(toffee, toffee + n, 1);
	for (int i = 0; i < n; i++) {
		if (isBottom(i)) {
			toffee[i] = max(toffee[i], 1);
			dfs(i);
		}
	}

	for (int i = 0; i < n; i++) {
		cout << (i ? " " : "") << toffee[i];
	}
	cout << '\n';
}
