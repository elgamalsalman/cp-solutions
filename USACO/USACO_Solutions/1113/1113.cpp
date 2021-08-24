#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int N, prefixSum[2'000'050];
ll ans;
vi a;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  for (int i = 0; i < N; i++) {
    int tmp; cin >> tmp;
    prefixSum[tmp]++;
    a.push_back(tmp);
  }
  sort(a.begin(), a.end());
  partial_sum(prefixSum, prefixSum + 2'000'020, prefixSum);

  int mx = *max_element(a.begin(), a.end());
  for (int i = 1; i <= mx; i++) {
    int i1 = i, i2 = i * 2;
    int oddCount = 0, pileCount = prefixSum[i2 - 1] - prefixSum[i1 - 1], ansPileCount;
    bool isFirstOdd = (pileCount % 2 != 0), oddAfterOdd = 0;
    if (isFirstOdd) {
      oddCount++;
      ansPileCount = pileCount;
    }
    bool isCurrOdd = 0, isPrevOdd = isFirstOdd;
    i1 = i2;
    while (i1 <= mx) {
      i2 = i1 + i;
      pileCount = prefixSum[i2 - 1] - prefixSum[i1 - 1];
      isCurrOdd = (pileCount % 2 != 0);
      if (isCurrOdd) oddCount++;
      if (isCurrOdd && isPrevOdd) {
	ansPileCount = pileCount;
	oddAfterOdd = 1;
      }

      isPrevOdd = isCurrOdd;
      i1 = i2;
    }

    if ((isFirstOdd && oddCount == 1) || (oddCount == 2 && oddAfterOdd)) ans += ansPileCount;
  }

  cout << ans << '\n';
}
