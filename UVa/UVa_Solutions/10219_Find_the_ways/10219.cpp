#include<bits/stdc++.h>

using namespace std;

int n, k;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> n >> k) {
    if (k > (n - k)) k = n - k;

    double digitCount = 0;
    for (int i = n - k + 1; i <= n; i++) digitCount += log10(i);
    for (int i = 2; i <= k; i++) digitCount -= log10(i);

    cout << (int) digitCount + 1 << '\n';
  }
}
