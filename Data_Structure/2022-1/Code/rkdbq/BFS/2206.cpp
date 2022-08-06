#define X first.first
#define Y first.second
#define Z second
#define INT_MAX 2000000001

#include <iostream>
#include <queue>
using namespace std;

int n, m;
bool map[1001][1001];
int vis[1001][1001][2];
queue<pair<pair<int, int>, bool>> q;
int dx[6]{1, -1, 0, 0, 0, 0};
int dy[6]{0, 0, 1, -1, 0, 0};

void bfs()
{
  while (!q.empty())
  {
    int curX{q.front().X};
    int curY{q.front().Y};
    bool curZ{q.front().Z};

    for (int i{}; i < 6; i++)
    {
      int nxtX{curX + dx[i]};
      int nxtY{curY + dy[i]};

      if (0 > nxtX || nxtX >= n)
        continue;
      if (0 > nxtY || nxtY >= m)
        continue;
      if (vis[nxtX][nxtY][curZ] != INT_MAX)
        continue;
      if (map[nxtX][nxtY])
      {
        if (curZ == false)
        {
          q.push({{nxtX, nxtY}, true});
          vis[nxtX][nxtY][true] = vis[curX][curY][curZ] + 1;
        }
        else
          continue;
      }
      else
      {
        q.push({{nxtX, nxtY}, curZ});
        vis[nxtX][nxtY][curZ] = vis[curX][curY][curZ] + 1;
      }
    }
    q.pop();
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  string num;
  for (int i{}; i < n; i++)
  {
    cin >> num;
    for (int j{}; j < m; j++)
    {
      map[i][j] = num[j] - '0';
    }
  }

  for (int i{}; i < n; i++)
  {
    for (int j{}; j < m; j++)
    {
      vis[i][j][false] = vis[i][j][true] = INT_MAX;
    }
  }
  q.push({{0, 0}, false});
  vis[0][0][false] = 1;
  bfs();
  int ans{min(vis[n - 1][m - 1][false], vis[n - 1][m - 1][true])};
  if (ans == INT_MAX)
    ans = -1;
  cout << ans << "\n";
  return 0;
}