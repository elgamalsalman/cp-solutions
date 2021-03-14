#include<bits/stdc++.h>

using namespace std;

int	lis, currLis, n, car, pos[100050];

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> car;
		pos[car - 1] = i;
	}

	lis = currLis = 1;
	for (int i = 1; i < n; i++) {
		if (pos[i] > pos[i - 1]) currLis++;
		else currLis = 1;
		lis = max(lis, currLis);
	}

	cout << n - lis << '\n';
}
