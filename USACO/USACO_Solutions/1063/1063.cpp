#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

ll ans, grid[2550][2550], N, Psum[2550][2550];
vii cows;

ll sumRect(int a, int b, int c, int d) {
  int r1 = min(a, c); int r2 = max(a, c);
  int c1 = min(b, d); int c2 = max(b, d);
  ll sum = Psum[r2][c2];
  if (r1) sum -= Psum[r1 - 1][c2];
  if (c1) sum -= Psum[r2][c1 - 1];
  if (r1 && c1) sum += Psum[r1 - 1][c1 - 1];
  return sum;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int cowR, cowC;
    cin >> cowR >> cowC;
    cows.push_back({cowR, cowC});
  }

  sort(cows.begin(), cows.end());
  for (int i = 0; i < N; i++) cows[i].fi = i;
  sort(cows.begin(), cows.end(), [](const ii& ele1, const ii& ele2) {
      return ele1.se < ele2.se;
      });
  for (int i = 0; i < N; i++) cows[i].se = i;
  for (int i = 0; i < N; i++) grid[cows[i].fi][cows[i].se] = 1;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      Psum[i][j] = grid[i][j];
      if (i) Psum[i][j] += Psum[i - 1][j];
      if (j) Psum[i][j] += Psum[i][j - 1];
      if (i && j) Psum[i][j] -= Psum[i - 1][j - 1];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      ll minR = min(cows[i].fi, cows[j].fi);
      ll maxR = max(cows[i].fi, cows[j].fi);
      ll minC = min(cows[i].se, cows[j].se);
      ll maxC = max(cows[i].se, cows[j].se);
      ll lPointsCount = sumRect(minR, 0, maxR, minC);
      ll rPointsCount = sumRect(minR, maxC, maxR, N - 1);
      ans += lPointsCount * rPointsCount;
    }
  }

  cout << ans + 1 << '\n';
}
