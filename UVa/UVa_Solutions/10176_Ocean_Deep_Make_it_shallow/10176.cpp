#include <bits/stdc++.h>

using namespace std;

int bitInd;
bitset<10050> num;

void reverseNum() {
  for (int i = 0; i < 1e4 / 2; i++) if (num[i] != num[1e4 - i - 1]) {
    num.flip(i);
    num.flip(1e4 - i - 1);
  }
}

bool isDivisible(int startInd) {
  if (startInd == 1e4) return 1;
  if (num[startInd]) {
    int operand = 1;
    for (int i = 0; i + startInd < 1e4; i++) {
      int newInd = i + startInd;
      if (operand % 2) {
	if (num[newInd] == 1) num[newInd] = 0;
	else {
	  num[newInd] = 1;
	  operand++;
	}
      }
      operand /= 2;

      if (i < 16) operand++;
    }

    if (operand) return 0;
  }
  return isDivisible(startInd + 1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (cin.peek() != EOF) {
    char c = cin.get();
    if (c == '1') num[bitInd++] = 1;
    else if (c == '0') bitInd++;
    else if (c == '#') {
      bitInd = 0;
      reverseNum();
      cout << (isDivisible(0) ? "YES" : "NO") << '\n';
      num.reset();
    }
  }
}
