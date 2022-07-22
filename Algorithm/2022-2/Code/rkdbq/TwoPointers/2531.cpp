#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int n, d, k, c;
int sushi[33001];
multiset<int> ate;
int cnt;
int ans;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> d >> k >> c;
  for (int i = 0; i < n; i++)
    cin >> sushi[i];
  for (int i = n; i < n + k - 1; i++)
    sushi[i] = sushi[i - n];
  ate.insert(c);
  cnt++;
  for (int i = 0; i < n + k - 1; i++)
  {
    if (i >= k)
    {
      ate.erase(ate.find(sushi[i - k]));
      if (ate.find(sushi[i - k]) == ate.end())
        cnt--;
    }
    if (ate.find(sushi[i]) == ate.end())
      cnt++;
    ate.insert(sushi[i]);
    // cout<<sushi[i]<<" ";
    // cout<<cnt<<"\n";
    ans = max(ans, cnt);
  }
  cout << ans << "\n";
  return 0;
}