#include<bits/stdc++.h>

using namespace std;

int	maxSum, n, a[100'050];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int maxEle = 30; maxEle > 0; maxEle--) {
		int currSum = 0;
		for (int i = 0; i < n; i++) {
			currSum += a[i];
			if (a[i] > maxEle || currSum < 0) currSum = 0;
			maxSum = max(maxSum, currSum - maxEle);
		}
	}

	cout << maxSum << '\n';
}
