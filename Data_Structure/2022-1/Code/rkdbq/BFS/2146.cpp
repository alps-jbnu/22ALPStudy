#define MAX 2000000001
#define X first.first
#define Y first.second
#define Length second

#include <iostream>
#include <queue>
using namespace std;

int n;
int country[101][101];
int minLen;
int islandCnt;
int firstIslandCnt;

int dx[4]{1, -1, 0, 0};
int dy[4]{0, 0, 1, -1};
bool visited[101][101][201];
int finished[101][101];
queue<pair<pair<int, int>, int>> Q;

void init()
{
  islandCnt = 0;
  for (int i{}; i < 101; i++)
  {
    for (int j{}; j < 101; j++)
    {
      for (int k{}; k <= minLen; k++)
      {
        visited[i][j][k] = false;
      }
      finished[i][j] = MAX;
    }
  }
}

void bfs()
{
  while (!Q.empty())
  {
    int curX{Q.front().X};
    int curY{Q.front().Y};
    int curLen{Q.front().Length};
    Q.pop();
    for (int i{}; i < 4; i++)
    {
      int nxtX{curX + dx[i]};
      int nxtY{curY + dy[i]};

      if (nxtX < 0 || nxtX >= n)
        continue;
      if (nxtY < 0 || nxtY >= n)
        continue;
      if (visited[nxtX][nxtY][curLen])
        continue;

      if (country[nxtX][nxtY] && finished[nxtX][nxtY] > curLen)
      { // land
        Q.push({{nxtX, nxtY}, curLen});
        visited[nxtX][nxtY][curLen] = true;
        finished[nxtX][nxtY] = curLen;
      }
      else if (curLen < minLen && finished[nxtX][nxtY] > curLen + 1)
      { // sea
        Q.push({{nxtX, nxtY}, curLen + 1});
        visited[nxtX][nxtY][curLen + 1] = true;
        finished[nxtX][nxtY] = curLen + 1;
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i{}; i < n; i++)
  {
    for (int j{}; j < n; j++)
    {
      cin >> country[i][j];
    }
  }

  while (true)
  {
    init();
    for (int i{}; i < n; i++)
    {
      for (int j{}; j < n; j++)
      {
        if (country[i][j] && finished[i][j] == MAX)
        {
          visited[i][j][0] = true;
          finished[i][j] = 0;
          Q.push({{i, j}, 0});
          bfs();
          islandCnt++;
        }
      }
    }
    if (minLen == 0)
      firstIslandCnt = islandCnt;
    else if (firstIslandCnt > islandCnt)
      break;
    minLen++;
  }
  cout << minLen << "\n";

  return 0;
}