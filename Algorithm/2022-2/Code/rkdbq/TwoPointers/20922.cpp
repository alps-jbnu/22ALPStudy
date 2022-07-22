#include <iostream>
using namespace std;

int n, k;
int a[200001];
int cnt[100001];
int st;
int ans;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
  {
    cnt[a[i]]++;
    while (cnt[a[i]] > k)
    {
      cnt[a[st]]--;
      st++;
    }
    ans = max(ans, i - st + 1);
  }
  cout << ans << "\n";
  return 0;
}