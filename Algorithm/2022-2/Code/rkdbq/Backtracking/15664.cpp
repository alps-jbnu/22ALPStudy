#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int n, m;
vector<int> ans;
set<vector<int>> S;
int seq[9];
int vis[9];

void dfs(int cur)
{
  if (ans.size() == m)
  {
    S.insert(ans);
    return;
  }
  for (int nxt{cur + 1}; nxt < n; nxt++)
  {
    if (!vis[nxt])
    {
      vis[nxt] = true;
      ans.push_back(seq[nxt]);
      dfs(nxt);
      vis[nxt] = false;
      ans.pop_back();
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
  for (auto it{S.begin()}; it != S.end(); it++)
  {
    auto cur{*it};
    for (int i{}; i < cur.size(); i++)
    {
      cout << cur[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}