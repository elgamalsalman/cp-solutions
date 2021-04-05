#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define ww first
#define vv second

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int	dis[105], currFloor, n, d, speeds[10];
vvii	adj;

void dijkstra () {
	fill(dis, dis + 105, 1e9);
	dis[0] = 0;
	priority_queue<ii, vii, greater<ii>> pq;
	pq.push({dis[0], 0});
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		if (front.ww > dis[front.vv]) continue;
		for (int i = 0; i < (int)adj[front.vv].size(); i++) {
			ii edge = adj[front.vv][i];
			int newWeight = edge.ww + front.ww;
			if (front.vv) newWeight += 60;
			if (newWeight < dis[edge.vv]) {
				dis[edge.vv] = newWeight;
				pq.push({dis[edge.vv], edge.vv});
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n >> d) {
		adj.assign(105, vii());

		for (int i = 0; i < n; i++) cin >> speeds[i];
		for (int i = 0; i < n; i++) {
			vi floors;
			
			cin.ignore();
			while (cin.peek() != '\n') {
				cin >> currFloor;
				floors.push_back(currFloor);
			}

			for (int j = 0; j < (int)floors.size(); j++) {
				for (int k = j + 1; k < (int)floors.size(); k++) {
					int w = speeds[i] * (floors[k] - floors[j]);
					adj[floors[j]].push_back({w, floors[k]});
					adj[floors[k]].push_back({w, floors[j]});
				}
			}

		}

		dijkstra();

		if (dis[d] == 1e9) cout << "IMPOSSIBLE";
		else cout << dis[d];
		cout << '\n';
	}
}
