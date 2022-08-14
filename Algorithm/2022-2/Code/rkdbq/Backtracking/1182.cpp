#include <iostream>
#include <algorithm>
using namespace std;

int n, s;
int ans, sum;
int seq[21];
bool vis[21];

void show() {
  cout<<"\n";
  for(int i{}; i<n; i++) {
    cout<<vis[i]<<" ";
  }
  cout<<"\n";
}

void dfs(int cur)
{
  // show();
  if (sum == s && cur != -1)
  {
    ans++;
  }
  for (int nxt{cur + 1}; nxt < n; nxt++)
  {
    if (!vis[nxt])
    {
      vis[nxt] = true;
      sum += seq[nxt];
      dfs(nxt);
      vis[nxt] = false;
      sum -= seq[nxt];
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> s;
  for (int i{}; i < n; i++)
  {
    cin >> seq[i];
  }
  dfs(-1);
  cout << ans;
  return 0;
}