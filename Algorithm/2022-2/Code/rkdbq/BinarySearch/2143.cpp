#define INT_MAX 2000000001

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t, n, m;
int a[1001], b[1001];
vector<long long> subA;
vector<long long> subB;
long long ans;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  cin >> n;
  for (int i{}; i < n; i++)
    cin >> a[i];
  cin >> m;
  for (int i{}; i < m; i++)
    cin >> b[i];

  for (int i{}; i < n; i++)
  {
    subA.push_back(a[i]);
    for (int j{i + 1}; j < n; j++)
    {
      subA.push_back(subA[subA.size() - 1] + a[j]);
    }
  }
  for (int i{}; i < m; i++)
  {
    subB.push_back(b[i]);
    for (int j{i + 1}; j < m; j++)
    {
      subB.push_back(subB[subB.size() - 1] + b[j]);
    }
  }

  sort(subA.begin(), subA.end());
  sort(subB.begin(), subB.end());

  for (int i{}; i < subA.size(); i++)
    cout << subA[i] << " ";
  cout << "\n";
  for (int i{}; i < subB.size(); i++)
    cout << subB[i] << " ";
  cout << "\n";

  for (int i{}; i < subA.size(); i++)
  {
    auto er{equal_range(subB.begin(), subB.end(), t - subA[i])};
    ans += er.second - er.first;
  }
  cout << ans << "\n";

  return 0;
}