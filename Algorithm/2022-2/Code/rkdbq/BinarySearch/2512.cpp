#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int region[10001];
int ans;

int total(int max)
{
  int ret = 0;
  for (int i = 0; i < n; i++)
  {
    if (region[i] <= max)
      ret += region[i];
    else
      ret += max;
  }
  return ret;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> region[i];
  }
  cin >> m;
  sort(region, region + n);

  int st = 1;
  int en = region[n - 1];

  while (st <= en)
  {
    int mid = (st + en) / 2;
    if (m < total(mid))
      en = mid - 1;
    else
    {
      st = mid + 1;
      ans = max(ans, mid);
    }
  }
  cout << ans << "\n";

  return 0;
}