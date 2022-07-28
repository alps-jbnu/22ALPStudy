#define INT_MAX 2000000001

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, h[601];
int ans = INT_MAX;
vector<pair<int, pair<int, int>>> snowman;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i{}; i < n; i++)
    cin >> h[i];
  for (int i{}; i < n - 1; i++)
  {
    for (int j{i + 1}; j < n; j++)
    {
      snowman.push_back({h[i] + h[j], {i, j}});
    }
  }
  sort(snowman.begin(), snowman.end());
  for (int i{}; i < snowman.size() - 1; i++)
  {
    for (int j{i + 1}; j < snowman.size(); j++)
    {
      if (snowman[i].second.first == snowman[j].second.first)
        continue;
      else if (snowman[i].second.first == snowman[j].second.second)
        continue;
      else if (snowman[i].second.second == snowman[j].second.first)
        continue;
      else if (snowman[i].second.second == snowman[j].second.second)
        continue;
      else
      {
        //cout << snowman[i].first << " " << snowman[j].first << "\n";
        ans = min(ans, snowman[j].first - snowman[i].first);
        break;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}