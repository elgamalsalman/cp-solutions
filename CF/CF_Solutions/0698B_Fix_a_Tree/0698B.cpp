#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int	j, changes, chosenRoot = -1, a, n;

class UFDS {
	int	num;
	vi	p;

	public:
		UFDS (int _n) {
			num = _n;
			p.resize(num + 20, 0);
			for (int i = 1; i <= num; i++) p[i] = i;
		}

		int findSet (int u) {
			return (u == p[u] ? u : findSet(p[u]));
		}

		int sameSet (int u, int v) {return findSet(u) == findSet(v);}

		void unionSet (int u, int v) {
			if (sameSet(u, v)) {
				if (u == v) chosenRoot = v;
				p[u] = 0;
				changes++;
				return;
			}
			p[u] = v;
		}

		void print () {
			for (int i = 1; i <= num; i++) {
				if (p[i] == 0 && chosenRoot == -1) chosenRoot = i;
				cout << (i == 1 ? "" : " ") << (p[i] == 0 ? chosenRoot : p[i]);
			} cout << '\n';
		}
};

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n; 
	UFDS graph(n);
	for (int i = 1; i <= n; i++) {
		cin >> j;
		graph.unionSet(i, j);
	}

	if (chosenRoot != -1) changes--;
	cout << changes << '\n';
	graph.print();
}
