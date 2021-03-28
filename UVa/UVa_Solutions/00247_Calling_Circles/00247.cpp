#include<bits/stdc++.h>

using namespace std;

typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef stack<int> si;

int	tcNum, dfsCounter, dfsNum[30], dfsLow[30], callerCounter, n, m;
bitset<30>	inStack;
string	s1, s2;
msi	dict;
vvi	adj;
si	sccStack;

string findCallerWithInd (int ind) {
	for (auto it = dict.begin(); it != dict.end(); it++) {
		if (it->second == ind) return it->first;
	}
}

void findScc (int u) {
	dfsNum[u] = dfsLow[u] = ++dfsCounter;
	sccStack.push(u);
	inStack[u] = 1;

	for (int i = 0; i < (int) adj[u].size(); i++) {
		int v = adj[u][i];
		if (dfsNum[v] == -1) findScc(v);
		if (inStack[v]) dfsLow[u] = min(dfsLow[u], dfsLow[v]);
	}

	if (dfsNum[u] == dfsLow[u]) {
		bool firstEle = 1; int ele;
		do {
			ele = sccStack.top();
			inStack[ele] = 0;
			sccStack.pop();
			if (firstEle) firstEle = 0;
			else cout << ", ";
			cout << findCallerWithInd(ele);
		} while (ele != u);
		cout << '\n';
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n >> m, n || m) {
		inStack.reset();
		callerCounter = 0;
		dict.clear();
		adj.assign(n + 20, vi());
		memset(dfsNum, -1, sizeof dfsNum);

		int u, v;
		for (int i = 0; i < m; i++) {
			cin >> s1 >> s2;
			if (dict.count(s1)) u = dict[s1];
			else u = dict[s1] = callerCounter++;

			if (dict.count(s2)) v = dict[s2];
			else v = dict[s2] = callerCounter++;

			adj[u].push_back(v);
		}

		if (tcNum) cout << '\n';
		cout << "Calling circles for data set " << ++tcNum << ":\n";
		for (int i = 0; i < callerCounter; i++) {
			if (dfsNum[i] == -1) findScc(i);
		}

		//for (int i = 0; i < callerCounter; i++) {
		//	cerr << "// " << findCallerWithInd(i) << " : (" << dfsNum[i] << ", " << dfsLow[i] << ")\n";
		//}
	}
}
