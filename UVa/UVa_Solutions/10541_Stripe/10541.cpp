#include<bits/stdc++.h>

using namespace std;

class BigInt {
  string raw;

  public:
    BigInt() { raw = "0"; }
    BigInt(int i) { raw = to_string(i); }
    BigInt(string s) { raw = s; }
    
    string str() { return raw; }

    BigInt operator+(BigInt operand) {
      string s1 = raw, s2 = operand.str(), ans = "";
      int n1 = (int) s1.size(), n2 = (int) s2.size();
      reverse(s1.begin(), s1.end());
      reverse(s2.begin(), s2.end());

      if (n1 > n2) for (int i = 0; i < n1 - n2; i++) s2 += '0';
      if (n2 > n1) for (int i = 0; i < n2 - n1; i++) s1 += '0';
      int n = max(n1, n2);

      int carry = 0;
      for (int i = 0; i < n; i++) {
	int digit1 = s1[i] - '0', digit2 = s2[i] - '0';
	int sum = digit1 + digit2 + carry;
	ans += '0' + sum % 10;
	carry = sum / 10;
      }

      if (carry) ans += '0' + carry;
      reverse(ans.begin(), ans.end());

      return BigInt(ans);
    }

    void operator+=(BigInt operand) { raw = (*this + operand).str(); }; 

    BigInt operator*(BigInt operand) {
      if (operand.str() == "0") return 0;

      string s1 = raw, s2 = operand.str();
      int n1 = (int) s1.size(), n2 = (int) s2.size();
      if (n2 > n1) { swap(s1, s2); swap(n1, n2); }

      reverse(s1.begin(), s1.end());
      reverse(s2.begin(), s2.end());

      BigInt ans = 0;
      for (int i = 0; i < n2; i++) {
	int operandDigit = s2[i] - '0';
	string subAns = "";
	int carry = 0;
	for (int j = 0; j < n1; j++) {
	  int digit = s1[j] - '0';
	  int sum = digit * operandDigit + carry;
	  subAns += '0' + sum % 10;
	  carry = sum / 10;
	}
	if (carry) subAns += '0' + carry;
	reverse(subAns.begin(), subAns.end());
	for (int k = 0; k < i; k++) subAns += '0';

	ans += subAns;
      }
      
      return ans;
    }

    void operator*=(BigInt operand) { raw = (*this * operand).str(); }; 
};

int primeDivs[205], tc, N, K, leastFactor[205];

void sieve() {
  memset(leastFactor, -1, sizeof leastFactor);
  for (int i = 2; i <= 205; i++) {
    if (leastFactor[i] != -1) continue;
    for (int j = i * i; j <= 205; j += i) {
      if (leastFactor[j] == -1) leastFactor[j] = i;
    }
  }
}

void addPrimeDivsOf(int i) {
  if (leastFactor[i] == -1) primeDivs[i]++;
  else {
    primeDivs[leastFactor[i]]++;
    addPrimeDivsOf(i / leastFactor[i]);
  }
}

BigInt nCr(int n, int r) {
  bitset<205> dividedByI;
  dividedByI.reset();

  r = min(r, n - r);

  memset(primeDivs, 0, sizeof primeDivs);
  for (int i = 2; i <= r; i++) addPrimeDivsOf(i);

  BigInt ans = 1;
  for (int i = n - r + 1; i <= n; i++) {
    int m = i;
    for (int j = 2; j <= r; j++) {
      while (primeDivs[j] && !(m % j)) {
	primeDivs[j]--;
	m /= j;
      }
    }
    ans *= m;
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve();

  cin >> tc;
  while (tc--) {
    cin >> N >> K;
    int darkCount = 0;
    for (int i = 0; i < K; i++) {
      int tmp; cin >> tmp;
      darkCount += tmp;
    }

    int whiteCount = N - darkCount;
    if (K > whiteCount + 1) cout << "0\n";
    else {
      cout << nCr(whiteCount + 1, K).str() << '\n';
    }
  }
}
