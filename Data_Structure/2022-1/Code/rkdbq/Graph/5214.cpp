#define HT 100000
#define MX 101001

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

set<int> adj[MX];
int n, k, m;

queue<int> Q;
int vis[MX];

void show()
{
  cout << "\n";
  for (int i{}; i < n; i++)
  {
    for (auto j{adj[i].begin()}; j != adj[i].end(); j++)
    {
      cout << *j << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

void bfs()
{
  while (!Q.empty())
  {
    int cur{Q.front()};
    Q.pop();
    for (auto it{adj[cur].begin()}; it != adj[cur].end(); it++)
    {
      int nxt{*it};
      if (vis[nxt] != -1)
        continue;

      if (nxt > HT)
        vis[nxt] = vis[cur];
      else
        vis[nxt] = vis[cur] + 1;
      Q.push(nxt);
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  fill(vis, vis + MX, -1);
  cin >> n >> k >> m;

  int htCnt{};
  for (int i{}; i < m; i++)
  {
    htCnt++;
    vector<int> hyperTube;
    for (int j{}; j < k; j++)
    {
      int station;
      cin >> station;
      hyperTube.push_back(station);
    }
    for (int j{}; j < k; j++)
    {
      int node{hyperTube[j]};
      adj[HT + htCnt].insert(node);
      adj[node].insert(HT + htCnt);
    }
  }

  // show();
  vis[1] = 1;
  Q.push(1);
  bfs();

  cout << vis[n];

  return 0;
}