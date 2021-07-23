#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int startingPoint, N, R, degrees[205];
bitset<205> visited, isAnIntersection;
vvi adj;

void dfs(int u) {
  visited[u] = 1;
  for (int v : adj[u]) {
    if (!visited[v]) dfs(v);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> N >> R) {
    startingPoint = 0;
    adj.assign(N, vi());
    memset(degrees, 0, sizeof degrees);
    isAnIntersection.reset();
    while (R--) {
      int u, v;
      cin >> u >> v;
      degrees[u]++;
      degrees[v]++;
      adj[u].push_back(v);
      adj[v].push_back(u);
      isAnIntersection[u] = isAnIntersection[v] = 1;
      startingPoint = u;
    }

    bool valid = 1;
    for (int i = 0; i < N; i++) if (degrees[i] % 2) valid = 0;

    visited.reset();
    dfs(startingPoint);
    if ((isAnIntersection ^ visited).count()) valid = 0;

    cout << (valid ? "Possible" : "Not Possible") << '\n';
  }
}
