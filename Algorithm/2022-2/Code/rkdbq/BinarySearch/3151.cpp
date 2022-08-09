#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[10001];
long long ans;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i{}; i < n; i++)
  {
    cin >> a[i];
  }
  sort(a, a + n);

  for (int i{}; i < n - 2; i++)
  {
    for (int j{i + 1}; j < n - 1; j++)
    {
      auto er{equal_range(a + j + 1, a + n, -(a[i] + a[j]))};
      //if(er.second-er.first) cout<<a[i]<<" "<<a[j]<<" "<<-(a[i]+a[j])<<"\n";
      ans += er.second - er.first;
    }
  }
  cout << ans << "\n";

  return 0;
}