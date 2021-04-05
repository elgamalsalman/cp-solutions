#include<bits/stdc++.h>

using namespace std;

int	tcNum, numPresses[10050], buttons[15], L, U, R;

void bfs () {
	queue<int> q;
	q.push(L);

	memset(numPresses, -1, sizeof numPresses);
	numPresses[L] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < R; i++) {
			int v = (u + buttons[i]) % 10000;
			if (numPresses[v] != -1) continue;
			numPresses[v] = numPresses[u] + 1;
			q.push(v);

			if (v == U) return;
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while (cin >> L >> U >> R, L || U || R) {
		for (int i = 0; i < R; i++) cin >> buttons[i];
		bfs();
		cout << "Case " << ++tcNum << ": ";
		if (numPresses[U] == -1) cout << "Permanently Locked";
		else cout << numPresses[U];
		cout << '\n';
	}
}
