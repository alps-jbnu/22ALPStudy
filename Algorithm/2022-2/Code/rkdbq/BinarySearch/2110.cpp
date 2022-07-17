#include <iostream>
#include <algorithm>
using namespace std;

int n, c, ans;
int house[200001];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> c;

  for (int i = 0; i < n; i++)
  {
    cin >> house[i];
  }
  sort(house, house + n);

  int st, en;
  st = 1;
  en = house[n - 1];
  while (st <= en)
  {
    int mid = (st + en) / 2;
    int cnt = 1;
    int bef = house[0];
    int nxt = house[1];
    int idx = 1;

    while (true)
    {
      if (idx == n)
        break;
      
      nxt = house[idx];
      if (mid <= nxt - bef)
      {
        bef = nxt;
        cnt++;
      }
      idx++;
    }

    if (cnt >= c)
    {
      st = mid + 1;
      ans = max(ans, mid);
    }
    else
      en = mid - 1;
  }
  cout << ans << "\n";

  return 0;
}