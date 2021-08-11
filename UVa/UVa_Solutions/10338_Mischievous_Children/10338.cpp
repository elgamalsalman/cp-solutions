#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int tcNum, tc, letterCount[30];
ll ans;
string word;

ll fact(int operand) {
  ll ans = 1;
  for (int i = 2; i <= operand; i++) ans *= i;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> word;
    memset(letterCount, 0, sizeof letterCount);
    for (char letter : word) letterCount[letter - 'A']++;
    ans = fact(word.size());
    for (int i : letterCount) ans /= fact(i);
    cout << "Data set " << ++tcNum << ": " << ans << '\n';
  }
}
