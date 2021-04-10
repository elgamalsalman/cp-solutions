#include <bits/stdc++.h>

using namespace std;

#define vv first
#define op second
#define OR 0
#define XOR 1

typedef pair<int, int> ii;
typedef vector<int> vi;

int	ind, newVal, ele, n, m;
vi	a;

class ST {
	vi s, st;
	int n;

	int left (int i) {return i << 1;}
	int right (int i) {return (i << 1) + 1;}

	ii init (int stI, int L, int R) {
		if (L == R) return {st[stI] = s[L], XOR};
		else {
			ii l = init(left(stI), L, (L + R)/2);
			ii r = init(right(stI), (L + R)/2 + 1, R);

			if (l.op == OR) return {st[stI] = l.vv ^ r.vv, XOR};
			else return {st[stI] = l.vv | r.vv, OR};
		}
	}

	ii update (int stI, int L, int R, int i, int val) {
		if (L > R) cout << "// erred in update\n";
		if (L == R) return {st[stI] = s[L], XOR};
		else if (i <= (L + R)/2) {
			ii l = update(left(stI), L, (L + R)/2, i, val);
			if (l.op == OR) return {st[stI] = l.vv ^ st[right(stI)], XOR};
			else return {st[stI] = l.vv | st[right(stI)], OR};
		} else {
			ii r = update(right(stI), (L + R)/2 + 1, R, i, val);
			if (r.op == OR) return {st[stI] = st[left(stI)] ^ r.vv, XOR};
			else return {st[stI] = st[left(stI)] | r.vv, OR};
		}
	}

	public:
		ST (vi _s) : s(_s) , n((int)_s.size()) {
			st.assign(n * 3, 0);
			s.insert(s.begin(), 0);
			init(1, 1, n);
		}

		void update (int i, int val) {
			s[i] = val;
			update(1, 1, n, i, val);
		}

		int query () {return st[1];}
};

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	n = pow(2, n);

	for (int i = 0; i < n; i++) {
		cin >> ele;
		a.push_back(ele);
	}

	ST st(a);

	for (int i = 0; i < m; i++) {
		cin >> ind >> newVal;
		st.update(ind, newVal);
		cout << st.query() << '\n';
	}
}
