#include <iostream>
using namespace std;

int n, k;
int s[1000001];
int cnt, cur, ans;
int st, en;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  for (int i{}; i < n; i++)
  {
    cin >> s[i];
  }
  while (true)
  {
    if (en == n || st > en)
      break;
    while (cnt <= k)
    {
      if (en == n)
        break;
      if (s[en++] % 2 == 0)
        cur++;
      else
        cnt++;
    }
    //cout<<cur<<"\n";
    ans = max(ans, cur);
    while (cnt > k)
    {
      if (st > en)
        break;
      if (s[st++] % 2 == 0)
        cur--;
      else
        cnt--;
    }
    //cout<<cur<<"\n";
  }
  cout << ans << "\n";
  //cout<<st<<" "<<en<<"\n";

  return 0;
}