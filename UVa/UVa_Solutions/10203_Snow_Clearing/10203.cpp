#include <bits/stdc++.h>

using namespace std;

int x, y, tc;
double dis;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> tc;
  while (tc--) {
    dis = 0;
    cin >> x >> y; cin.ignore();

    while (cin.peek() != '\n' && cin.peek() != EOF) {
      int x1, x2, y1, y2;

      cin >> x1 >> y1 >> x2 >> y2; cin.ignore();

      dis += hypot(abs(x1 - x2), abs(y1 - y2));
    }

    dis *= 2;
    dis /= 20000;

    int minutes = round((dis - (int) dis) * 60);
    int hours = dis;
    if (minutes == 60) { minutes = 0; hours++; }

    cout << hours << ':' << setw(2) << setfill('0') << minutes << '\n';
    if (tc) cout << '\n';
  }
}

