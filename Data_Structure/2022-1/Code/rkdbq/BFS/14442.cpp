#define MAX 1001
#define INT_MAX 2000000001

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Info
{
public:
  int x;
  int y;
  int brk;
};

int n, m, k;
bool map[MAX][MAX];

int dx[4]{1, -1, 0, 0};
int dy[4]{0, 0, 1, -1};
int vis[MAX][MAX][11];
queue<Info> Q;

void showMap()
{
  for (int i{}; i < n; i++)
  {
    for (int j{}; j < m; j++)
    {
      cout << map[i][j];
    }
    cout << "\n";
  }
}
void bfs()
{
  while (!Q.empty())
  {
    Info cur{Q.front()};
    Q.pop();
    for (int i{}; i < 4; i++)
    {
      Info nxt{cur};
      nxt.x += dx[i];
      nxt.y += dy[i];
      if (nxt.x < 0 || nxt.x >= n)
        continue;
      if (nxt.y < 0 || nxt.y >= m)
        continue;
      if (vis[nxt.x][nxt.y][nxt.brk] != INT_MAX)
        continue;
      if (map[nxt.x][nxt.y])
      {
        nxt.brk++;
        if (vis[nxt.x][nxt.y][nxt.brk] != INT_MAX)
          continue;
        if (nxt.brk > k)
          continue;
      }
      Q.push(nxt);
      vis[nxt.x][nxt.y][nxt.brk] = vis[cur.x][cur.y][cur.brk] + 1;
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i{}; i < MAX; i++)
  {
    for (int j{}; j < MAX; j++)
    {
      for (int k{}; k < 11; k++)
      {
        vis[i][j][k] = INT_MAX;
      }
    }
  }
  cin >> n >> m >> k;
  for (int i{}; i < n; i++)
  {
    string c;
    cin >> c;
    for (int j{}; j < m; j++)
    {
      map[i][j] = c[j] - '0';
    }
  }
  Info st;
  st.x = st.y = st.brk = 0;
  Q.push(st);
  vis[st.x][st.y][st.brk] = 1;
  bfs();

  // cout<<"\n";
  // showMap();
  // cout<<"\n";

  int ans{*min_element(vis[n - 1][m - 1], vis[n - 1][m - 1] + k + 1)};
  if (ans == INT_MAX)
    ans = -1;
  cout << ans;

  return 0;
}