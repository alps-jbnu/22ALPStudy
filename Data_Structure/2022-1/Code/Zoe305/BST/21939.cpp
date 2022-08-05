#include <bits/stdc++.h>
using namespace std;

string op;
int N, L, P, x;
int probLevel[100'002];
set<int> probByLevel[102];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  while (N--) {
    cin >> P >> L;
    probLevel[P] = L;
    probByLevel[L].insert(P);
  }
  cin >> N;
  while (N--) {
    cin >> op;
    if (op == "recommend") {
      cin >> x;
      if (x == 1) {
        for (int i = 100; 0 <= i; i--) {
          if (probByLevel[i].empty()) continue;
          cout << *(prev(probByLevel[i].end())) << '\n';
          break;
        }
      } else {
        for (int i = 0; i < 101; i++) {
          if (probByLevel[i].empty()) continue;
          cout << *probByLevel[i].begin() << '\n';
          break;
        }
      }
    } else if (op == "add") {
      cin >> P >> L;
      probLevel[P] = L;
      probByLevel[L].insert(P);
    } else if (op == "solved") {
      cin >> P;
      probByLevel[probLevel[P]].erase(P);
    }
  }
}