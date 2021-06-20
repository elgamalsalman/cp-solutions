#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, ll> ill;
typedef pair<int, int> ii;
typedef pair<ii, ll> iill;
typedef vector<ill> vill;
typedef vector<iill> viill;

ll	in[100'050], out[100'050], n, m;
vill	netIn, netOut;
viill	ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		out[u] += d;
		in[v] += d;
	}

	for (int i = 1; i <= n; i++) {
		if (out[i] > in[i]) netOut.push_back({i, out[i] - in[i]});
		else if (out[i] < in[i]) netIn.push_back({i, in[i] - out[i]});
	}

	int inInd = 0, outInd = 0;
	while (inInd < netIn.size()) {
		if (netIn[inInd].se == 0) inInd++;
		else if (netOut[outInd].se == 0) outInd++;
		else {
			ll debt = min(netIn[inInd].se, netOut[outInd].se);
			ans.push_back({{netOut[outInd].fi, netIn[inInd].fi}, debt});
			netIn[inInd].se -= debt;
			netOut[outInd].se -= debt;
		}
	}

	cout << ans.size() << '\n';
	for (iill currDebt : ans) {
		cout << currDebt.fi.fi << ' ' << currDebt.fi.se << ' ' << currDebt.se << '\n';
	}
}
