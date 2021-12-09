#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N, ans;

ll bSearch(ll target) {
  ll l = 1, r = N + 1;
  while (l < r) {
    ll mid = (l + r) / 2;
    ll curr = N / mid;
    if (curr < target) r = mid;
    else l = mid + 1;
  }

  return r;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  ll curr = N, currDiv = 1;
  do {
    ll nextDiv = bSearch(curr);
    ll inc = curr * (nextDiv - currDiv);
    ans += inc;
    curr = N / nextDiv;
    currDiv = nextDiv;
  } while (curr);

  cout << ans << '\n';
}
