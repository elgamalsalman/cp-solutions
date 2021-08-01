#include<bits/stdc++.h>

using namespace std;

long long n, fact[25];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  fact[0] = 1;
  for (int i = 1; i <= 20; i++) fact[i] = fact[i - 1] * i;

  bool firstCase = 1;
  while (cin >> n) {
    if (firstCase) firstCase = 0;
    else cout << '\n';
    cout << fact[n * 2] / (fact[n] * fact[n]) / (n + 1) << '\n';
  }
}
