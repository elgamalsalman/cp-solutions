#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N, tcNum;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> N && N) {
    cout << "Case " << ++tcNum << ": " << (ll) ceil((3 + sqrt((double) (9 + 8 * N))) / 2.0) << '\n';
  }
}
