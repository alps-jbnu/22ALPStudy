#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> ans;
int seq[9];

void dfs(int cur)
{
  if (ans.size() == m)
  {
    for (int i{}; i < m; i++)
    {
      cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return;
  }
  for (int nxt{cur}; nxt < n; nxt++)
  {
    ans.push_back(seq[nxt]);
    dfs(nxt);
    ans.pop_back();
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
  dfs(0);
  return 0;
}