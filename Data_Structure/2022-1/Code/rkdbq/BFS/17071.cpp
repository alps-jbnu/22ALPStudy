#define MAX 500001

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Position
{
public:
  int n;
  int k;
  int dk;
};

int n, k;
int points[MAX][2];
int seconds;

int dx[2]{1, -1};
queue<Position> Q;

int bfs()
{
  while (!Q.empty())
  {
    auto cur{Q.front()};
    Q.pop();
    // cout << cur.n << " " << cur.k << " " << points[cur.n][0] << " " << cur.dk << "\n";
    // cout << cur.n << " " << cur.k << " " << points[cur.n][1] << " " << cur.dk << "\n";
    for (int i{}; i < 2; i++)
    {
      if ((points[cur.k][i] != -1) && (points[cur.k][i] <= cur.dk) && (points[cur.k][i] % 2 == cur.dk % 2))
      {
        // cout << points[cur.k][i] << " " << cur.k << " " << cur.dk << "\n";
        return cur.dk;
      }
    }
    for (int i{}; i < 2; i++)
    {
      auto nxt{cur};
      nxt.n += dx[i];
      nxt.dk += 1;
      nxt.k += nxt.dk;
      if (nxt.n < 0 || nxt.n >= MAX)
        continue;
      if (nxt.k < 0 || nxt.k >= MAX)
        continue;
      if (points[nxt.n][nxt.dk % 2] != -1)
        continue;
      Q.push(nxt);
      points[nxt.n][nxt.dk % 2] = points[cur.n][cur.dk % 2] + 1;
    }
    auto nxt{cur};
    nxt.n *= 2;
    nxt.dk += 1;
    nxt.k += nxt.dk;
    if (nxt.n < 0 || nxt.n >= MAX)
      continue;
    if (nxt.k < 0 || nxt.k >= MAX)
      continue;
    if (points[nxt.n][nxt.dk % 2] != -1)
      continue;
    Q.push(nxt);
    points[nxt.n][nxt.dk % 2] = points[cur.n][cur.dk % 2] + 1;
  }
  return -1;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i{}; i < MAX; i++)
    points[i][0] = points[i][1] = -1;
  cin >> n >> k;
  points[n][0] = 0;
  Position st;
  st.n = n;
  st.k = k;
  st.dk = 0;
  Q.push(st);
  cout << bfs();

  return 0;
}