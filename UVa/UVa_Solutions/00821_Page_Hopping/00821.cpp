#include<bits/stdc++.h>

using namespace std;

int	n, tcNum, a, b, dis[105][105];
double	total;
bitset<105>	pages;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 105; i++) fill(dis[i], dis[i] + 105, 1000);
	while (1) {
		cin >> a >> b;
		pages[a] = pages[b] = 1;
		dis[a][b] = 1;
		if (!a && !b) {
			n = pages.count() - 1;
			if (!n) break;

			for (int i = 1; i <= 100; i++)
				for (int j = 1; j <= 100; j++)
					for (int k = 1; k <= 100; k++)
						dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);

			for (int i = 1; i <= 100; i++) {
				for (int j = 1; j <= 100; j++) {
					if (i == j) continue;
					if (dis[i][j] != 1000) {
						total += dis[i][j];
					}
				}
			}

			cout << "Case " << ++tcNum << ": average length between pages = " << fixed << setprecision(3) << total / (n * (n - 1)) << " clicks\n";

			for (int i = 0; i < 105; i++) fill(dis[i], dis[i] + 105, 1000);
			total = 0;
			pages.reset();
		}
	}
}
