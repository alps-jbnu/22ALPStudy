#include <iostream>
#include <algorithm>
using namespace std;

int n, a[1000001];
int LIS[1000001];
int ans;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++)
  {
    if (LIS[ans] < a[i])
    {
      LIS[++ans] = a[i];
    }
    else if (LIS[ans] > a[i])
    {
      auto up = lower_bound(LIS, LIS + ans, a[i]);
      *up = a[i];
    }
  }
  cout << ans << "\n";

  return 0;
}