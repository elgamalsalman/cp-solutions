#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

int	vCounter, p[100050], n, bitsNum[100], dis[100050];
ll	a[100050];
vvi	adj, numbersWithBit(100);
bitset<100050>	visited;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	adj.assign(n, vi());
	for (int j = 0; j < n; j++) {
		ll num;
		cin >> num;
		a[j] = num;
		for (int i = 0; i < 64; i++) {
			if ((1LL << i) & num) {
				bitsNum[i]++;
				numbersWithBit[i].push_back(vCounter);
			}
		}
		vCounter++;
	}

	for (int i = 0; i < 100; i++) if (bitsNum[i] >= 3) {
		cout << "3\n";
		return 0;
	}

	for (int i = 0; i < 64; i++) {
		if (numbersWithBit[i].size() == 2) {
			int u = numbersWithBit[i][0], v = numbersWithBit[i][1];
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}

	int ans = 1e9;
	for (int u = 0; u < n; u++) {
		for (int v : adj[u]) {
			bool done = 0;

			memset(dis, -1, sizeof dis);
			visited.reset();
			queue<int> q;
			q.push(u);
			visited[u] = dis[u] = 1;
			while (!done && !q.empty()) {
				int top = q.front(); q.pop();
				for (int j : adj[top]) {
					if ((top == u && j == v) || (top == v && j == u)) continue;
					if (!visited[j]) {
						p[j] = top;
						dis[j] = dis[top] + 1;
						visited[j] = 1;
						q.push(j);
						if (j == v && p[top] != u) { done = 1; break; }
					} 
				}
			}

			if (dis[v] != -1 && ans > dis[v]) {
				ans = dis[v];
			}
		}
	}

	cout << (ans == 1e9 ? -1 : ans) << '\n';
}
