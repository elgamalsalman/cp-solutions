#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vi> vvi;

bool	reachable[1050][1050];
int	tc, eventCounter, NM, NC, NE;
map<string, int>	eventToInd;

string indToEvent(int i) {
	for (pair<string, int> ele : eventToInd) {
		if (ele.se == i) return ele.fi;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> NC && NC) {
		memset(reachable, 0, sizeof reachable);
		eventToInd.clear();

		eventCounter = 1;
		for (int v = 0; v < NC; v++) {
			cin >> NE;
			string events[NE];
			for (int j = 0; j < NE; j++) {
				cin >> events[j];
				if (!eventToInd[events[j]]) eventToInd[events[j]] = eventCounter++;
			}

			for (int j = 1; j < NE; j++) reachable[eventToInd[events[j - 1]]][eventToInd[events[j]]] = 1;
		}

		cin >> NM;
		for (int j = 0; j < NM; j++) {
			string sender, reciever;
			cin >> sender >> reciever;
			reachable[eventToInd[sender]][eventToInd[reciever]] = 1;
		}

		for (int k = 1; k < eventCounter; k++) {
			for (int i = 1; i < eventCounter; i++) {
				for (int j = 1; j < eventCounter; j++) {
					reachable[i][j] |= (reachable[i][k] && reachable[k][j]);
				}
			}
		}

		int concurrentCount = 0;
		for (int i = 1; i < eventCounter; i++) {
			for (int j = i + 1; j < eventCounter; j++) {
				if (i == j) continue;
				if (!reachable[i][j] && !reachable[j][i]) concurrentCount++;
			}
		}

		if (!concurrentCount) cout << "Case " << ++tc << ", no concurrent events.\n";
		else {
			cout << "Case " << ++tc << ", " << concurrentCount << " concurrent events:\n";
			if (concurrentCount > 2) concurrentCount = 2;
			int k = 0;
			for (int i = 1; k < concurrentCount; i++) {
				for (int j = i + 1; j < eventCounter && k < concurrentCount; j++) {
					if (!reachable[i][j] && !reachable[j][i]) {
						k++;
						cout << "(" << indToEvent(i) << ',' << indToEvent(j) << ") ";
					}
				}
			}
			cout << '\n';
		}
	}
}
