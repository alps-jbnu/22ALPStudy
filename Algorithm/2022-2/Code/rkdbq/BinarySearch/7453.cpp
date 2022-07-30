#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long a[4001], b[4001], c[4001], d[4001];
long long cd[4001 * 4001];
long long ans;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i{}; i < n; i++)
  {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }

  int cdIdx{};
  for (int i{}; i < n; i++)
  {
    for (int j{}; j < n; j++)
    {
      cd[cdIdx++] = c[i] + d[j];
    }
  }
  sort(cd, cd + cdIdx);

  for (int i{}; i < n; i++)
  {
    for (int j{}; j < n; j++)
    {
      auto er{equal_range(cd, cd+cdIdx, -(a[i]+b[j]))};
      ans += er.second-er.first;
    }
  }

  cout << ans << "\n";

  return 0;
}