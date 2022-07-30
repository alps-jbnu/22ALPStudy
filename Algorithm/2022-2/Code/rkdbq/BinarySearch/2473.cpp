#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

int n;
long long sol[5001];
long long bef{LLONG_MAX};
int ans[3];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i{}; i < n; i++)
  {
    cin >> sol[i];
  }
  sort(sol, sol + n);

  for (int i{}; i < n - 2; i++)
  {
    for (int j{i + 1}; j < n - 1; j++)
    {
      int st{j + 1};
      int en{n - 1};
      while (st <= en)
      {
        int mid{(st + en) / 2};
        long long cur{sol[i] + sol[j] + sol[mid]};
        //cout<<cur<<"\n";
        //cout<<sol[mid]<<"\n";
        if (cur < 0)
        {
          st = mid + 1;
        }
        else
        {
          en = mid - 1;
        }
        if (bef > abs(cur))
        {
          bef = abs(cur);
          ans[0] = sol[i];
          ans[1] = sol[j];
          ans[2] = sol[mid];
        }
      }
    }
  }
  for (int i{}; i < 3; i++)
    cout << ans[i] << " ";

  return 0;
}