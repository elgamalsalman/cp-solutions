#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n, m;
vvi adj;
vi removalOrder;
vector<string> answers;

struct {
  int n, setCount;
  vi p, h, state;
  void init(int _n) {
    n = _n;
    setCount = 0;
    p.assign(n, 0);
    for (int i = 0; i < n; i++) p[i] = i;
    h.assign(n, 0);
    state.assign(n, 0);
  }
  bool isOn(int ind) { return state[ind]; }
  void turnOn(int ind) { state[ind] = 1; setCount++; }
  int getSet(int i) { return (i == p[i] ? i : p[i] = getSet(p[i])); }
  bool isSameSet(int i, int j) { return (getSet(i) == getSet(j)); }
  void mergeSets(int i, int j) {
    if (isSameSet(i, j)) return;
    setCount--;
    i = getSet(i);
    j = getSet(j);
    if (h[i] > h[j]) p[j] = i;
    else {
      p[i] = j;
      if (h[i] == h[j]) h[j]++;
    }
  }
} dsu;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  freopen("closing.in", "r", stdin);
  freopen("closing.out", "w", stdout);

  cin >> n >> m;
  adj.assign(n + 20, vi());
  dsu.init(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    tmp--;
    removalOrder.push_back(tmp);
  }
  reverse(removalOrder.begin(), removalOrder.end());
  
  for (int i = 0; i < n; i++) {
    int barn = removalOrder[i];
    dsu.turnOn(barn);
    for (int adjBarn : adj[barn]) {
      if (dsu.isOn(adjBarn)) dsu.mergeSets(barn, adjBarn);
    }
    
    if (dsu.setCount == 1) answers.push_back("YES");
    else answers.push_back("NO");
  }
  reverse(answers.begin(), answers.end());

  for (int i = 0; i < n; i++) cout << answers[i] << '\n';
}
