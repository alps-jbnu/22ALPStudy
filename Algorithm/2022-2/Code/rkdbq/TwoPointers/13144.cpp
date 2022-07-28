#include <iostream>
#include <algorithm>
using namespace std;

int n;
int s[100001];
bool chk[100001];
unsigned long long ans;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> s[i];

  int st = 0;
  int en = 0;

  for (st = 0; st < n; st++)
  {
    while (en < n)
    {
      if (chk[s[en]])
        break;
      chk[s[en++]] = true;
    }
    ans += (en - st);
    chk[s[st]] = false;
  }
  cout << ans << "\n";

  return 0;
}