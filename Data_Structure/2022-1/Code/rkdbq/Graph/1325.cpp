#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[10001];
bool vis[10001];
int ans[10001], st;
int n, m;

void dfs(int cur)
{
  vis[cur] = true;
  ans[st]++;
  for (int i{}; i < adj[cur].size(); i++)
  {
    int nxt{adj[cur][i]};
    if (vis[nxt])
      continue;
    else
      dfs(nxt);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i{}; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[v].push_back(u);
  }
  for (int i{1}; i <= n; i++)
  {
    fill(vis, vis+10001, false);
    st = i;
    dfs(i);
    // cout << ans[i] << "\n";
  }
  int max{*max_element(ans + 1, ans + n + 1)};
  for (int i{1}; i <= n; i++)
    if (ans[i] == max)
      cout << i << " ";
  return 0;
}