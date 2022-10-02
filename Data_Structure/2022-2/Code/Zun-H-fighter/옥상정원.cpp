#include <bits/stdc++.h>

using namespace std;

stack<int> s;
int n;
long long sum;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  long long h;
  while (n--) {
    cin >> h;
    while(!s.empty() && s.top() <= h)
      s.pop();
    sum += s.size();
    s.push(h);
  }
  cout << sum;
  return 0;
}
