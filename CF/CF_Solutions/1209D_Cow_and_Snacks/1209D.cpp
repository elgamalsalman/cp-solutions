#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n, k;
vvi adj;
bitset<100'050> taken, visited;

void dfs(int u) {
  visited[u] = 1;
  for (int v : adj[u]) if (!visited[v]) dfs(v);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  adj.assign(n, vi());
  for (int i = 0; i < k; i++) {
    int u, v;
    cin >> u >> v; u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    taken[u] = taken[v] = 1;
  }

  int x = taken.count();
  int ccCount = 0;
  for (int i = 0; i < n; i++) {
    if (taken[i] && !visited[i]) {
      dfs(i);
      ccCount++;
    }
  }
  cout << k - (x - ccCount) << '\n';
}
