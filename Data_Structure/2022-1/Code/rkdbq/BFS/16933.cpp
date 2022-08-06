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
  bool isDay;
};

int n, m, k;
bool map[MAX][MAX];

int dx[5]{1, -1, 0, 0, 0};
int dy[5]{0, 0, 1, -1, 0};
int vis[MAX][MAX][11][2];
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

void showVis()
{
  for (int l{}; l < 2; l++)
  {
    for (int k{}; k < 4; k++)
    {
      for (int i{}; i < n; i++)
      {
        for (int j{}; j < m; j++)
        {
          if (vis[i][j][k][l] == INT_MAX)
            cout << 0;
          else
            cout << vis[i][j][k][l];
        }
        cout << "\n";
      }
      cout << "\n";
    }
    cout << "\n";
  }
  cout << "\n";
}

void bfs()
{
  while (!Q.empty())
  {
    Info cur{Q.front()};
    Q.pop();
    for (int i{}; i < 5; i++)
    {
      Info nxt{cur};
      nxt.x += dx[i];
      nxt.y += dy[i];
      nxt.isDay = !cur.isDay;
      if (nxt.x < 0 || nxt.x >= n)
        continue;
      if (nxt.y < 0 || nxt.y >= m)
        continue;
      if (vis[nxt.x][nxt.y][nxt.brk][nxt.isDay] != INT_MAX)
        continue;
      if (map[nxt.x][nxt.y])
      {
        if (nxt.isDay)
        { // cur is night
          if (vis[nxt.x][nxt.y][nxt.brk][!nxt.isDay] == INT_MAX)
            continue;
        }
        else
        {
          nxt.brk++;
          if (vis[nxt.x][nxt.y][nxt.brk][nxt.isDay] != INT_MAX)
            continue;
          if (nxt.brk > k)
            continue;
        }
      }
      Q.push(nxt);
      vis[nxt.x][nxt.y][nxt.brk][nxt.isDay] = vis[cur.x][cur.y][cur.brk][cur.isDay] + 1;

      // cout << "nxt " << nxt.x << " " << nxt.y << " " << nxt.brk << " " << nxt.isDay << "\n";
      // cout << vis[nxt.x][nxt.y][nxt.brk][nxt.isDay] << "\n";
      // cout << "cur " << cur.x << " " << cur.y << " " << cur.brk << " " << cur.isDay << "\n";
      // cout << vis[cur.x][cur.y][cur.brk][cur.isDay] << "\n";
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
        for (int l{}; l < 2; l++)
        {
          vis[i][j][k][l] = INT_MAX;
        }
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
  st.isDay = true;
  Q.push(st);
  vis[st.x][st.y][st.brk][st.isDay] = 1;
  bfs();

  // cout<<"\n";
  // showVis();
  // cout<<"\n";

  int ans{INT_MAX};
  for (int k{}; k < 11; k++)
  {
    for (int l{}; l < 2; l++)
    {
      // cout<<k<<" "<<l<<" "<<vis[n - 1][m - 1][k][l]<<"\n";
      ans = min(ans, vis[n - 1][m - 1][k][l]);
    }
  }
  if (ans == INT_MAX)
    ans = -1;
  cout << ans;

  return 0;
}