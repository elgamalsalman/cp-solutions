#include <bits/stdc++.h>

using namespace std;

int n, pattern[80];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  pattern[1] = 1;
  pattern[2] = pattern[3] = 2;
  for (int i = 4; i <= 76; i++) pattern[i] = pattern[i - 2] + pattern[i - 3];

  while (cin >> n) cout << pattern[n] << '\n';
}
