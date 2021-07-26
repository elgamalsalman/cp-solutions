#include<bits/stdc++.h>

using namespace std;

int digitCount[120];
string fib1, fib2;

bool isValidFib() {
  bool isPrevOn = 0;
  for (int i = 0; i < 110; i++) {
    if (digitCount[i]) {
      if (isPrevOn || digitCount[i] > 1) return 0;
      else isPrevOn = 1;
    } else isPrevOn = 0;
  }

  return 1;
}

void printResultingFib() {
  bool fibBegan = 0;
  for (int i = 110; i >= 0; i--) {
    if (digitCount[i]) {
      cout << digitCount[i];
      fibBegan = 1;
    } else if (fibBegan) cout << 0;
  }
  
  if (!fibBegan) cout << 0;
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  bool firstTC = 1;
  while (cin >> fib1 >> fib2) {
    if (!firstTC) cout << '\n';
    else firstTC = 0;

    memset(digitCount, 0, sizeof digitCount);
    int n1 = fib1.size();
    int n2 = fib2.size();
    for (int i = 0; i < n1; i++) if (fib1[i] == '1') digitCount[n1 - i - 1]++;
    for (int i = 0; i < n2; i++) if (fib2[i] == '1') digitCount[n2 - i - 1]++;

    while (!isValidFib()) {
      for (int i = 0; i < 110; i++) {
	if (digitCount[i] && digitCount[i + 1]) {
	  digitCount[i]--;
	  digitCount[i + 1]--;
	  digitCount[i + 2]++;
	}
      }

      if (digitCount[0] >= 2) {
	digitCount[0] -= 2;
	digitCount[1]++;
      }

      if (digitCount[1] >= 2) {
	digitCount[1] -= 2;
	digitCount[2]++;
	digitCount[0]++;
      }

      for (int i = 2; i < 110; i++) {
	if (digitCount[i] >= 2) {
	  digitCount[i] -= 2;
	  digitCount[i - 2]++;
	  digitCount[i + 1]++;
	}
      }
    }

    printResultingFib();
  }
}
