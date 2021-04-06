#include<bits/stdc++.h>

using namespace std;

vector<int>	places;
int	minE, e, a, N, dis[2][30][30];
char	age, dir, u, v, uY, uM;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> N, N) {
		places.clear();
		for (int i = 0; i < 30; i++) {
			fill(dis[0][i], dis[0][i] + 30, 1e9);
			fill(dis[1][i], dis[1][i] + 30, 1e9);
			dis[0][i][i] = dis[1][i][i] = 0;
		}

		minE = 1e9;

		for (int i = 0; i < N; i++) {
			cin >> age >> dir >> u >> v >> e;
			if (age == 'Y') a = 0;
			else a = 1;
			dis[a][u - 'A'][v - 'A'] = min(dis[a][u - 'A'][v - 'A'], e);
			if (dir == 'B') dis[a][v - 'A'][u - 'A'] = min(dis[a][v - 'A'][u - 'A'] ,e);
		}

		cin >> uY >> uM;

		for (int a = 0; a < 2; a++)
			for (int i = 0; i < 30; i++) 
				for (int j = 0; j < 30; j++)
					for (int k = 0; k < 30; k++)
						dis[a][j][k] = min(dis[a][j][k], dis[a][j][i] + dis[a][i][k]);

		for (int p = 0; p < 30; p++) {
			int currYE = dis[0][uY - 'A'][p];
			int currME = dis[1][uM - 'A'][p];
			if (currYE + currME < minE) {
				minE = currYE + currME;
				places = {p};
			} else if (currYE + currME == minE) places.push_back(p);
		}

		if (minE == 1e9) cout << "You will never meet.\n";
		else {
			cout << minE;
		       	for (int place : places) cout << ' ' << (char)('A' + place);
			cout << '\n';
		}
	}
}
