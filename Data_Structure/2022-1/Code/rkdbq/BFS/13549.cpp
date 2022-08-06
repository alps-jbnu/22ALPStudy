#define MAX 100001

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, k;
int points[MAX];
int seconds;

int dx[2]{1, -1};
queue<int> Q;

void bfs()
{
  while (!Q.empty())
  {
    int cur{Q.front()};
    Q.pop();
    int nxt{2 * cur};
    while (nxt < MAX)
    {
      if (nxt == 0)
        break;
      if (points[nxt] == -1)
      {
        Q.push(nxt);
        points[nxt] = points[cur];
      }
      nxt *= 2;
    }
    for (int i{}; i < 2; i++)
    {
      int nxt{cur + dx[i]};
      if (nxt < 0 || nxt >= MAX)
        continue;
      if (points[nxt] != -1)
        continue;
      Q.push(nxt);
      points[nxt] = points[cur] + 1;
    }
    if (points[k] != -1)
      break;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  fill(points, points + MAX, -1);
  cin >> n >> k;
  points[n] = 0;
  Q.push(n);
  bfs();
  cout << points[k];

  return 0;
}