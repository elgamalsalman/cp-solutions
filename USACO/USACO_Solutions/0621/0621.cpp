#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int n;
vvi barns;
vii cows;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  freopen("cbarn.in", "r", stdin);
  freopen("cbarn.out", "w", stdout);

  cin >> n;
  barns.assign(n, vi());
  cows.assign(n, {0, 0});
  int cowCounter = 0;
  for (int i = 0; i < n; i++) {
    int cowCount;
    cin >> cowCount;
    while (cowCount--) {
      cows[cowCounter] = {i, i};
      barns[i].push_back(cowCounter);
      cowCounter++;
    }
  }

  queue<ii> starts;
  for (int i = 0; i < 3 * n; i++) {
    int u = i % n;
    for (int cow : barns[u]) starts.push({u, cow});
    if (!starts.empty()) {
      ii startingPoint = starts.front(); starts.pop();
      cows[startingPoint.se] = {startingPoint.fi, i};
    }
  }

  ll cost = 0;
  for (ii cow : cows) {
    int u = cow.fi, v = cow.se;
    if (v < u) v += n;
    cost += pow(abs(v - u) % n, 2);
    //cerr << "// edge (" << u << ", \t" << v << ")\n";
  }

  cout << cost << '\n';
}
