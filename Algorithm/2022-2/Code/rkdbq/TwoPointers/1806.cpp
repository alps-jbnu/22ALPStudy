#define INT_MAX 2000000001

#include <iostream>
using namespace std;

int n, s;
int seq[100001];
int st, en;
int sum;
int ans = INT_MAX;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> s;
  for (int i = 0; i < n; i++)
    cin >> seq[i];

  while (true)
  {
    if (en == n && s > sum)
      break;
    if (s <= sum)
    {
      ans = min(ans, en - st);
      sum -= seq[st++];
    }
    else
      sum += seq[en++];
  }

  if (ans != INT_MAX)
    cout << ans << "\n";
  else
    cout << 0 << "\n";

  return 0;
}