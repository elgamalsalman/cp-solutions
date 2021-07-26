#include<bits/stdc++.h>

using namespace std;

int n;
string fib[1050];

string bigIntPlus(string num1, string num2) {
  reverse(num1.begin(), num1.end());
  reverse(num2.begin(), num2.end());
  int n1 = (int) num1.size(), n2 = (int) num2.size();
  if (n1 > n2) for (int i = 0; i < n1 - n2; i++) num2 += '0';
  if (n2 > n1) for (int i = 0; i < n2 - n1; i++) num1 += '0';

  string result = "";
  int n = max(n1, n2), carry = 0;
  for (int i = 0; i < n; i++) {
    int digit1 = num1[i] - '0';
    int digit2 = num2[i] - '0';
    int currSum = digit1 + digit2 + carry;

    result += (char) ('0' + currSum % 10);
    carry = currSum / 10;
  }

  if (carry) result += '0' + carry;
  reverse(result.begin(), result.end());

  return result;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  fib[0] = "1";
  fib[1] = "2";

  for (int i = 2; i <= 1000; i++) fib[i] = bigIntPlus(fib[i - 1], fib[i - 2]);
  while (cin >> n) cout << fib[n] << '\n';
}
