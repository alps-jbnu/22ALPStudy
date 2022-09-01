#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int cnt;
int seq[9];
bool vis[9];

void show()
{
  cout << "\n";
  for (int i{}; i < n; i++)
  {
    cout << vis[i] << " ";
  }
  cout << "\n";
}

void dfs(int cur)
{
  // show();
  if (cnt == m)
  {
    for (int i{}; i < n; i++)
    {
      if (vis[i])
        cout << seq[i] << " ";
    }
    cout<<"\n";
    return;
  }
  for (int nxt{cur + 1}; nxt < n; nxt++)
  {
    if (!vis[nxt])
    {
      vis[nxt] = true;
      cnt++;
      dfs(nxt);
      vis[nxt] = false;
      cnt--;
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i{}; i < n; i++)
  {
    cin >> seq[i];
  }
  sort(seq, seq + n);
  dfs(-1);
  return 0;
}