#define MAX 100001

#include <iostream>
using namespace std;

int t, n, choiceOf[MAX];
bool vis[MAX];
bool done[MAX];
int cnt;

void init()
{
  fill(choiceOf, choiceOf + MAX, 0);
  fill(vis, vis + MAX, false);
  fill(done, done + MAX, false);
  cnt = 0;
}

void dfs(int cur)
{
  vis[cur] = true;
  int nxt{choiceOf[cur]};
  if (!vis[nxt])
    dfs(nxt);
  else if (!done[nxt])
  {
    for (int i{nxt}; i != cur; i = choiceOf[i])
    {
      cnt++;
      done[i] = true;
    }
    cnt++;
  }
  done[cur] = true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  while (t--)
  {
    init();
    cin >> n;
    for (int i{1}; i <= n; i++)
    {
      cin >> choiceOf[i];
    }
    for (int i{1}; i <= n; i++)
    {
      if (!vis[i])
        dfs(i);
    }
    cout << n - cnt << "\n";
  }
  return 0;
}