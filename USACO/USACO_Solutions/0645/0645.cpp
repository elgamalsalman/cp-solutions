#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

ll minArea, totalArea;
ll N, minR, maxR, minC, maxC;
vii cows;

void compute() {
  vi pMinR, pMaxR, pMinC, pMaxC;
  vi rpMinR, rpMaxR, rpMinC, rpMaxC;

  pMinR.resize(N);
  pMaxR.resize(N);
  pMinC.resize(N);
  pMaxC.resize(N);
  rpMinR.resize(N);
  rpMaxR.resize(N);
  rpMinC.resize(N);
  rpMaxC.resize(N);

  for (int i = 0; i < N; i++) {
    if (!i) {
      pMinR[i] = pMaxR[i] = cows[i].fi;
      pMinC[i] = pMaxC[i] = cows[i].se;
    } else {
      pMinR[i] = min(pMinR[i - 1], cows[i].fi);
      pMaxR[i] = max(pMaxR[i - 1], cows[i].fi);
      pMinC[i] = min(pMinC[i - 1], cows[i].se);
      pMaxC[i] = max(pMaxC[i - 1], cows[i].se);
    }
  }

  for (int i = N - 1; i >= 0; i--) {
    if (i == N - 1) {
      rpMinR[i] = rpMaxR[i] = cows[i].fi;
      rpMinC[i] = rpMaxC[i] = cows[i].se;
    } else {
      rpMinR[i] = min(rpMinR[i + 1], cows[i].fi);
      rpMaxR[i] = max(rpMaxR[i + 1], cows[i].fi);
      rpMinC[i] = min(rpMinC[i + 1], cows[i].se);
      rpMaxC[i] = max(rpMaxC[i + 1], cows[i].se);
    }
  }

  for (int i = 0; i < N - 1; i++) {
    if (pMaxR[i] >= rpMinR[i + 1] && pMaxC[i] >= rpMinC[i + 1]) continue;
    ll newArea = ((pMaxR[i] - pMinR[i]) * (pMaxC[i] - pMinC[i])) + ((rpMaxR[i + 1] - rpMinR[i + 1]) * (rpMaxC[i + 1] - rpMinC[i + 1]));
    minArea = min(minArea, newArea);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  freopen("split.in", "r", stdin);
  freopen("split.out", "w", stdout);

  cin >> N;
  for (int i = 0; i < N; i++) {
    ll r, c;
    cin >> r >> c;
    if (!i) {
      minR = maxR = r;
      minC = maxC = c;
    } else {
      minR = min(minR, r);
      maxR = max(maxR, r);
      minC = min(minC, c);
      maxC = max(maxC, c);
    }
    cows.push_back({r, c});
  }
  minArea = totalArea = (maxR - minR) * (maxC - minC);

  sort(cows.begin(), cows.end());
  compute();

  sort(cows.begin(), cows.end(), [](ii ele1, ii ele2) {
      if (ele2.se > ele1.se || (ele2.se == ele1.se && ele2.fi > ele1.fi)) return 1;
      else return 0;
      });
  compute();

  cout << totalArea - minArea << '\n';
}
