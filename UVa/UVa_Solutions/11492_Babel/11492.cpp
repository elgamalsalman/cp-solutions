#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> ii;
typedef pair<int, string> is;
typedef vector<is> vis;
typedef vector<vis> vvis;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int	ans, dis[2050], M;
vvis	dict;
vvii	adj;
string	O, D;
map<string, int>	langs, words;

int dijkstra () {
	fill(dis, dis + 2050, 1e9);
	priority_queue<ii, vii, greater<ii>> pq;
	for (is w : dict[0]) {
		dis[w.fi] = w.se.size();
		pq.push({dis[w.fi], w.fi});
	}
	for (is w : dict[1]) adj[w.fi].push_back({0, M});

	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		if (front.fi > dis[front.se]) continue;
		if (front.se == M) return front.fi;
		for (int i = 0; i < (int)adj[front.se].size(); i++) {
			ii edge = adj[front.se][i];
			if (front.fi + edge.fi < dis[edge.se]) {
				dis[edge.se] = front.fi + edge.fi;
				pq.push({dis[edge.se], edge.se});
			}
		}
	}

	return -1;
}

int mapLang (string l) {
	if (!langs.count(l)) {
		langs[l] = langs.size();
		dict.emplace_back();
	}
	return langs[l];
}


int mapWord (string w, int l1, int l2) {
	if (!words.count(w)) words[w] = words.size();
	dict[l1].push_back({words[w], w});
	dict[l2].push_back({words[w], w});
	return words[w];
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> M, M) {
		adj.assign(M + 20, vii());
		dict.clear();
		langs.clear(); words.clear();

		cin >> O >> D;
		mapLang(O); mapLang(D);
		for (int i = 0; i < M; i++) {
			string l1, l2, w;
			cin >> l1 >> l2 >> w;
			mapWord(w, mapLang(l1), mapLang(l2));
		}

		for (int i = 0; i < (int)dict.size(); i++) {
			for (int j = 0; j < (int) dict[i].size(); j++) {
				for (int k = j + 1; k < (int)dict[i].size(); k++) {
					if (dict[i][j].se[0] == dict[i][k].se[0]) continue;

					adj[dict[i][k].fi].push_back({dict[i][j].se.size(), dict[i][j].fi});
					adj[dict[i][j].fi].push_back({dict[i][k].se.size(), dict[i][k].fi});
				}
			}
		}

		ans = dijkstra();
		if (ans == -1) cout << "impossivel";
		else cout << ans;
		cout << '\n';
	}
}
