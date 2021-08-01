#include <bits/stdc++.h>

using namespace std;

class BigInt {
  string s;
  public:
    BigInt() { s = "0"; }
    BigInt(int i) { s = to_string(i); }
    BigInt(string r) { s = r; }

    string str() { return s; }

    BigInt operator+(BigInt operand) {
      string s1 = s, s2 = operand.str();
      reverse(s1.begin(), s1.end());
      reverse(s2.begin(), s2.end());
      int n1 = s1.size(), n2 = s2.size();

      if (n1 > n2) for (int i = 0; i < n1 - n2; i++) s2 += '0';
      if (n2 > n1) for (int i = 0; i < n2 - n1; i++) s1 += '0';
      int n = max(n1, n2);

      string resS = "";
      int carry = 0;
      for (int i = 0; i < n; i++) {
	int digit1 = s1[i] - '0';
	int digit2 = s2[i] - '0';
	int sum = digit1 + digit2 + carry;
	resS += to_string(sum % 10);
	carry = sum / 10;
      }

      if (carry) resS += to_string(carry);

      reverse(resS.begin(), resS.end());
      return BigInt(resS);
    }

    void operator+=(BigInt operand) { s = (*this + operand).str(); }

    BigInt operator*(BigInt operand) {
      string s1 = s, s2 = operand.str();
      int n1 = s1.size(), n2 = s2.size();
      reverse(s1.begin(), s1.end());
      reverse(s2.begin(), s2.end());
      BigInt res;
      for (int i = 0; i < n2; i++) {
	int multiplier = s2[i] - '0';
	string currS = "";
	int carry = 0;
	for (int j = 0; j < n1; j++) {
	  int sum = multiplier * (s1[j] - '0') + carry;
	  currS += to_string(sum % 10);
	  carry = sum / 10;
	}
	if (carry) currS += to_string(carry);
	reverse(currS.begin(), currS.end());
	for (int j = 0; j < i; j++) currS += '0';
	res += BigInt(currS);
      }
      return res;
    }

    void operator*=(BigInt operand) { s = (*this * operand).str(); }
};

int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> n && n) {
    BigInt ans = 1;
    for (int i = n + 2; i <= 2 * n; i++) ans *= i;
    cout << ans.str() << '\n';
  }
}
