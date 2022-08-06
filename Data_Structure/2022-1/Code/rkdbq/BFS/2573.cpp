#define X first
#define Y second

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int sea[301][301];
int numOfIceberg;
int cnt;

queue<pair<int, int>> Q;
int dx[4]{0, 0, 1, -1};
int dy[4]{1, -1, 0, 0};
bool visited[301][301];

void init()
{
  numOfIceberg = 0;
  for (int i{}; i < 301; i++)
  {
    for (int j{}; j < 301; j++)
    {
      visited[i][j] = false;
    }
  }
}

void showSea()
{
  for (int i{}; i < n; i++)
  {
    for (int j{}; j < m; j++)
    {
      cout << sea[i][j] << " ";
    }
    cout << "\n";
  }
}

void bfs(bool melting)
{
  while (!Q.empty())
  {
    pair<int, int> cur{Q.front()};
    Q.pop();
    for (int i{}; i < 4; i++)
    {
      pair<int, int> nxt{cur.X + dx[i], cur.Y + dy[i]};
      if (nxt.X < 0 || nxt.X >= n)
        continue;
      if (nxt.Y < 0 || nxt.Y >= m)
        continue;
      if (visited[nxt.X][nxt.Y])
        continue;
      if (sea[nxt.X][nxt.Y] == 0)
      {
        if (melting && sea[cur.X][cur.Y] > 0)
          sea[cur.X][cur.Y]--;
      }
      else
      {
        visited[nxt.X][nxt.Y] = true;
        Q.push({nxt.X, nxt.Y});
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  int seaCnt{};
  for (int i{}; i < n; i++)
  {
    for (int j{}; j < m; j++)
    {
      cin >> sea[i][j];
      if (sea[i][j] == 0)
        seaCnt++;
    }
  }

  while (seaCnt)
  {
    init();
    for (int i{}; i < n; i++)
    {
      for (int j{}; j < m; j++)
      {
        if (sea[i][j] != 0 && !visited[i][j])
        {
          visited[i][j] = true;
          Q.push({i, j});
          bfs(true);
        }
      }
    }

    init();
    for (int i{}; i < n; i++)
    {
      for (int j{}; j < m; j++)
      {
        if (sea[i][j] != 0 && !visited[i][j])
        {
          visited[i][j] = true;
          Q.push({i, j});
          bfs(false);
          numOfIceberg++;
        }
      }
    }

    // cout<<"\n";
    // showSea();
    // cout<<numOfIceberg<<"\n";
    cnt++;

    if (numOfIceberg != 1)
      break;
  }
  if (numOfIceberg == 0)
    cnt = 0;
  cout << cnt << "\n";

  return 0;
}