#include <iostream>
#include <algorithm>
using namespace std;

int n;
int children[1000001];
bool chk[1000001];
int LIS[1000001];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i{}; i < n; i++)
    cin >> children[i];
  for (int i{}; i < n; i++)
  {
    chk[children[i]] = true;
    LIS[children[i]]++;
    if (chk[children[i] - 1])
      LIS[children[i]] = LIS[children[i] - 1] + 1;
  }
  cout << n - *max_element(LIS + 1, LIS + n + 1) << "\n";

  return 0;
}