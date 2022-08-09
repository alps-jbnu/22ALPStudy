#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, l;
int sa[101];
int ans{2000000001};
int cnt;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> l;
  sa[0] = 0;
  sa[n + 1] = l;
  for (int i{1}; i <= n; i++)
    cin >> sa[i];
  sort(sa, sa + n + 2);

  int st{0}, en{l};
  while (st <= en)
  {
    int mid{(st + en) + 1 / 2};
    if (mid == 0)
      break;
    for (int i{}; i < n + 1; i++)
    {
      // cout<<mid<<" "<<sa[i+1]-sa[i]<<" "<<cnt<<"\n";
      cnt += (sa[i + 1] - sa[i] - 1) / mid;
      // cout<<cnt<<"\n";
    }
    if (cnt <= m)
    {
      en = mid - 1;
      ans = min(ans, mid);
    }
    else
    {
      st = mid + 1;
    }
    cnt = 0;
  }

  cout << ans << "\n";

  return 0;
}