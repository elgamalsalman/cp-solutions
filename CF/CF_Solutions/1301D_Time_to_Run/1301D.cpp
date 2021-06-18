#include<bits/stdc++.h>

using namespace std;

int	stepC, n, m, k;
string	emptyStep = "", steps[3050];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	if (k > 4 * n * m - 2 * n - 2 * m) { cout << "NO\n"; return 0; }

	cout << "YES\n";
	for (int i = 0; i < n - 1 && k; i++) {
		if (m > 1) {
			int compoundSteps = k / 3;
			if (compoundSteps >= m - 1) {
				steps[stepC++] += to_string(m - 1) + " RDU\n";
				k -= (m - 1) * 3;
			} else {
				if (compoundSteps) steps[stepC++] += to_string(compoundSteps) + " RDU\n";
				k -= compoundSteps * 3;
				if (k) steps[stepC++] = "1 " + string("RDU").substr(0, k) + '\n';
				k = 0;
			}

			if (!k) break;

			if (k >= m - 1) {
				steps[stepC++] += to_string(m - 1) + " L\n";
				k -= m - 1;
			} else if (m > 1) {
				steps[stepC++] += to_string(k) + " L\n";
				k = 0;
				break;
			}

			if (!k) break;
		}

		if (k--) steps[stepC++] = "1 D\n";
	}

	if (m > 1) {
		if (k) {
			steps[stepC++] += to_string(min(m - 1, k)) + " R\n";
			k -= min(m - 1, k);
		}

		if (k) {
			steps[stepC++] += to_string(min(m - 1, k)) + " L\n";
			k -= min(m - 1, k);
		}
	}

	if (k) {
		steps[stepC++] += to_string(min(n - 1, k)) + " U\n";
		k -= min(n - 1, k);
	}

	cout << stepC << '\n';
	for (int i = 0; i < stepC; i++) {
		cout << steps[i];
	}
}
