#define INT_MAX 2000000001

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[100001];
int st, en;
int ans = INT_MAX;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  sort(a, a + n);
  st = 0;
  en = 1;
  int idx = 0;
  while (true)
  {
    if (en + idx == n)
      break;
    if (a[en + idx] - a[st] >= m)
    {
      ans = min(ans, a[en + idx] - a[st]);
      st++;
      en = st + 1;
      idx = -1;
    }
    idx++;
  }
  cout << ans << "\n";

  return 0;
}