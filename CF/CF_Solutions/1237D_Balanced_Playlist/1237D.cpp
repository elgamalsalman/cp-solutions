#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;

int	n, a[300'050];

class ST {
	vi	a, minSt, maxSt, st;
	int	n;

	int left(int i) { return (i << 1); }
	int right(int i) { return (i << 1) + 1; }

	void build(int p, int i, int j) {
		if (i == j) {
			minSt[p] = maxSt[p] = a[i];
			st[p] = 1;
		} else {
			int mid = (i + j) / 2;
			build(left(p), i, mid);
			build(right(p), mid + 1, j);
			maxSt[p] = max(maxSt[left(p)], maxSt[right(p)]);
			minSt[p] = min(minSt[left(p)], minSt[right(p)]);
			st[p] = 1;
			if (!st[left(p)] || !st[right(p)]) st[p] = 0;
			if (maxSt[left(p)] / 2.0 > minSt[right(p)]) st[p] = 0;
		}
	}

	iii isValidRange(int p, int i, int j, int L, int R) {
		if (j < L || i > R) return {-1, {0, 0}};
		if (i >= L && j <= R) return {st[p], {minSt[p], maxSt[p]}};
		
		iii l = isValidRange(left(p), i, (i+j)/2, L, R);
		iii r = isValidRange(right(p), (i+j)/2 + 1, j, L, R);

		if (l.fi == -1) return r;
		if (r.fi == -1) return l;

		if (!l.fi || !r.fi) return {0, {0, 0}};
		if (l.se.se / 2.0 > r.se.fi) return {0, {0, 0}};
		return {1, {min(l.se.fi, r.se.fi), max(l.se.se, r.se.se)}};
	}

	public:
		ST(const vi &_a) : a{_a}, n{(int) _a.size()} {
			minSt.assign(n * 4, 0);
			maxSt.assign(n * 4, 0);
			st.assign(n * 4, 0);
			build(1, 0, n - 1);
		}

		iii isValidRange(int L, int R) {
			return isValidRange(1, 0, n - 1, L, R);
		}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i + n] = a[i];
		a[i + 2*n] = a[i];
	}

	bool isInfinite = 1;
	int maxEle = a[0];
	for (int i = 0; i < n * 3; i++) {
		if (a[i] > maxEle) maxEle = a[i];
		if (a[i] < maxEle / 2.0) isInfinite = 0;
	}

	if (isInfinite) {
		for (int i = 0; i < n; i++) cout << -1 << " \n"[i == n - 1];
		return 0;
	}

	ST st(vi(a, a + n*3));

	for (int i = 0; i < n; i++) {
		int l = i, r = i + 2*n - 1;
		while (l < r) {
			int mid = (l + r + 1) / 2;
			iii res = st.isValidRange(i, mid);
			if (!res.fi) r = mid - 1;
			else l = mid;
		}

		cout << l - i + 1 << " \n"[i == n - 1];
	}
}
