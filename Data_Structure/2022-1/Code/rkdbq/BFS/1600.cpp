#define MAX 201
#define INT_MAX 2000000001

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Monkey
{
public:
  int x;
  int y;
  int horse;
  Monkey()
  {
    x = 0;
    y = 0;
    horse = 0;
  }
};

int k;
int w, h;
bool board[MAX][MAX];

int dx[4]{1, -1, 0, 0};
int dy[4]{0, 0, 1, -1};
int dxHorse[8]{1, -1, 1, -1, 2, -2, 2, -2};
int dyHorse[8]{2, 2, -2, -2, 1, 1, -1, -1};
int vis[MAX][MAX][31];
queue<Monkey> Q;

void showBoard(int k)
{
  for (int i{}; i < h; i++)
  {
    for (int j{}; j < w; j++)
    {
      cout << vis[i][j][k] << " ";
    }
    cout << "\n";
  }
}

void init()
{
  for (int i{}; i < MAX; i++)
  {
    for (int j{}; j < MAX; j++)
    {
      for (int k{}; k < 31; k++)
      {
        vis[i][j][k] = INT_MAX;
      }
    }
  }
}

void bfs()
{
  while (!Q.empty())
  {
    Monkey cur{Q.front()};
    Q.pop();
    for (int i{}; i < 8; i++)
    {
      Monkey nxt{cur};
      nxt.x += dxHorse[i];
      nxt.y += dyHorse[i];
      nxt.horse++;
      if (nxt.horse > k)
        continue; // overThanK
      if (nxt.x < 0 || nxt.x >= h)
        continue; // outOfMap
      if (nxt.y < 0 || nxt.y >= w)
        continue; // outOfMap
      if (board[nxt.x][nxt.y])
        continue; // obstacle
      if (vis[nxt.x][nxt.y][nxt.horse] != INT_MAX)
        continue; // visited
      Q.push(nxt);
      vis[nxt.x][nxt.y][nxt.horse] = vis[cur.x][cur.y][cur.horse] + 1;
    }
    for (int i{}; i < 4; i++)
    {
      Monkey nxt{cur};
      nxt.x += dx[i];
      nxt.y += dy[i];
      if (nxt.x < 0 || nxt.x >= h)
        continue; // outOfMap
      if (nxt.y < 0 || nxt.y >= w)
        continue; // outOfMap
      if (board[nxt.x][nxt.y])
        continue; // obstacle
      if (vis[nxt.x][nxt.y][nxt.horse] != INT_MAX)
        continue; // visited
      Q.push(nxt);
      vis[nxt.x][nxt.y][nxt.horse] = vis[cur.x][cur.y][cur.horse] + 1;
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> k;
  cin >> w >> h;
  for (int i{}; i < h; i++)
  {
    for (int j{}; j < w; j++)
    {
      cin >> board[i][j];
    }
  }

  init();
  Monkey st = Monkey();
  Q.push(st);
  vis[st.x][st.y][st.horse] = 0;
  bfs();

  // cout<<"\n";
  // for(int i{}; i<=k; i++) {
  //   showBoard(i);
  //   cout<<"\n";
  // }

  int ans{*min_element(vis[h - 1][w - 1], vis[h - 1][w - 1] + k + 1)};
  if (ans == INT_MAX)
    ans = -1;
  cout << ans;

  return 0;
}