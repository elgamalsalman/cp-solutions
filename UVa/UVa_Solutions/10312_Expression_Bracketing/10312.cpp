#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, supCat[30], cat[30];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  supCat[1] = supCat[2] = 1;
  for (int i = 3; i <= 26; i++) {
    supCat[i] = 0;
    for (int j = 1; j < i; j++) {
      supCat[i] += supCat[j] * supCat[i - j] * (i - j == 1 ? 1 : 2);
    }
  }

  cat[0] = cat[1] = 1;
  for (int i = 1; i < 26; i++) {
    cat[i + 1] = cat[i] * (2 * i + 1) * (2 * i + 2) / (i + 1) / (i + 2);
  }

  while (cin >> n) { cout << supCat[n] - cat[n-1] << '\n'; }
}
