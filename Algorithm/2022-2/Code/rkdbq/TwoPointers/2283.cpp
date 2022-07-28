#include <iostream>
using namespace std;

int n, k;
int a, b;
pair<int, int> lines[1001];
int cnt;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  for (int i{}; i < n; i++)
  {
    cin >> lines[i].first >> lines[i].second;
  }
  while (cnt != k)
  {
    if (cnt < k)
    {
      for (int i{}; i < n; i++)
      {
        if (lines[i].first <= b && b < lines[i].second)
          cnt++;
      }
      b++;
      if (b > 1000000)
      {
        a = b = 0;
        break;
      }
    }
    else if (cnt > k)
    {
      for (int i{}; i < n; i++)
      {
        if (lines[i].first <= a && a < lines[i].second)
          cnt--;
      }
      a++;
    }
  }
  cout << a << " " << b << "\n";

  return 0;
}