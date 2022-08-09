#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Position
{
public:
  int x;
  int y;
  Position(int x, int y)
  {
    this->x = x;
    this->y = y;
  }
};

int n, m;
vector<Position> switchInfo[101][101];
int ans;

int dx[4]{1, -1, 0, 0};
int dy[4]{0, 0, 1, -1};
bool isTurnedOn[101][101];
bool vis[101][101];
queue<Position> Bessie;

void show()
{
  for (int i{}; i < n; i++)
  {
    for (int j{}; j < m; j++)
    {
      if (isTurnedOn[i][j])
        cout << i << " " << j << "\n";
    }
    cout << "\n";
  }
}

void turnOn(int x, int y)
{
  for (int i{}; i < switchInfo[x][y].size(); i++)
  {
    Position sI{switchInfo[x][y][i]};
    if (isTurnedOn[sI.x][sI.y])
      continue;
    isTurnedOn[sI.x][sI.y] = true;
    ans++;
    // cout << sI.x << " " << sI.y << "\n";
  }
}

void bfs()
{
  while (!Bessie.empty())
  {
    Position cur{Bessie.front()};
    Bessie.pop();
    for (int i{}; i < 4; i++)
    {
      Position nxt{Position(cur.x + dx[i], cur.y + dy[i])};
      if (nxt.x < 1 || nxt.x > n)
        continue;
      if (nxt.y < 1 || nxt.y > m)
        continue;
      if (!isTurnedOn[nxt.x][nxt.y])
        continue;
      if (vis[nxt.x][nxt.y])
        continue;

      vis[nxt.x][nxt.y] = true;
      turnOn(nxt.x, nxt.y);
      Bessie.push(nxt);
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int j{}; j < m; j++)
  {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    switchInfo[x][y].push_back(Position(a, b));
  }
  vis[1][1] = true;
  isTurnedOn[1][1] = true;
  turnOn(1, 1);

  int befAns{-1};
  while (true)
  {
    if (befAns == ans)
      break;
    for (int i{1}; i <= n; i++)
    {
      for (int j{1}; j <= n; j++)
      {
        if (vis[i][j])
        {
          Bessie.push(Position(i, j));
        }
      }
    }
    befAns = ans;
    bfs();
  }

  // show();
  cout << ans + 1;

  return 0;
}