#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int	n;
ll	ans;
vi	cows;

class ST {
	int n;
	vi s, v;

	int left(int i) {return (i << 1);}
	int right(int i) {return (i << 1) + 1;}

	int rq(int p, int l, int r, int L, int R) {
		if (l > R || r < L) return 0;
		else if (l >= L && r <= R) return s[p];

		int lVal = rq(left(p), l, (l + r)/2, L, R);
		int rVal = rq(right(p), (l + r)/2 + 1, r, L, R);

		return lVal + rVal;
	}

	int update(int p, int l, int r, int i, int val) {
		if (l > i || r < i) return s[p];
		else if (l == r && l == i) return s[p] = v[i] = val;
		
		int lVal = update(left(p), l, (l + r)/2, i, val);
		int rVal = update(right(p), (l + r)/2 + 1, r, i, val);

		return s[p] = lVal + rVal;
	}

	public:
		ST (const vi &_v) : n((int) _v.size()), v(_v) {
			s.assign(n * 4, 0);
		}

		int rq(int l, int r) {
			return rq(1, 0, n - 1, l, r);
		}

		void update(int i, int val) {
			update(1, 0, n - 1, i, val);
		}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	map<int, int> lastOcc;
	cin >> n; cows.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> cows[i];
		lastOcc[cows[i]] = -1;
	}

	ST cowTree(vi(n, 0));
	for (int r = 0; r < n; r++) {
		cowTree.update(r - 1, 1);
		if (lastOcc[cows[r]] != -1) {
			cowTree.update(lastOcc[cows[r]], 0);
			ans += cowTree.rq(lastOcc[cows[r]] + 1, r);
		} else {
			ans += cowTree.rq(0, r);
		}
		lastOcc[cows[r]] = r;
	}

	cout << ans << '\n';
}
