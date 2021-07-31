#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll tcNum, tc, pascal[100][100], k;
string a, b;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> tc;
  while (tc--) {
    cin.ignore(2);
    a = b = "";

    while (1) {
      char letter = cin.get();
      if (letter == '+') break;
      a += letter;
    }

    while (1) {
      char letter = cin.get();
      if (letter == ')') break;
      b += letter;
    }

    cin.ignore();
    cin >> k;

    cout << "Case " << ++tcNum << ": ";

    memset(pascal, 0, sizeof pascal);
    for (int i = 0; i <= k; i++) {
      pascal[i][0] = 1;
      for (int j = 1; j <= i; j++) pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
    }
    
    int aPow = k, bPow = 0;
    for (int i = 0; i <= k; i++) {
      if (i) cout << '+';
      ll coeff = pascal[k][i];
      if (coeff != 1) cout << coeff << '*';
      if (aPow) cout << a << ((aPow == 1) ? "" : "^" + to_string(aPow));
      if (bPow) cout << (aPow ? "*" : "") << b << ((bPow == 1) ? "" : "^" + to_string(bPow));
      aPow--; bPow++;
    }
    cout << '\n';
  }
}
