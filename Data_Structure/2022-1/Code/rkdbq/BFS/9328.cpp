#include <iostream>
#include <queue>
using namespace std;

int t;
int h, w;
char building[101][101];
string key;
int doc;

int dx[4]{1, -1, 0, 0};
int dy[4]{0, 0, 1, -1};
bool vis[101][101];
int visCnt;
queue<pair<int, int>> Q;

void showBuilding()
{
  for (int i{}; i < h; i++)
  {
    for (int j{}; j < w; j++)
    {
      cout << building[i][j];
    }
    cout << "\n";
  }
  cout << "\n";
}

void showVis()
{
  for (int i{}; i < h; i++)
  {
    for (int j{}; j < w; j++)
    {
      cout << vis[i][j];
    }
    cout << "\n";
  }
  cout << "\n";
}

void init()
{
  for (int i{}; i < 101; i++)
  {
    for (int j{}; j < 101; j++)
    {
      building[i][j] = vis[i][j] = 0;
    }
  }
  doc = 0;
  visCnt = 0;
}

void unlock(char key)
{
  key += 'A' - 'a';
  for (int i{}; i < h; i++)
  {
    for (int j{}; j < w; j++)
    {
      if (building[i][j] == key)
      {
        building[i][j] = '.';
      }
    }
  }
}

void bfs()
{
  while (!Q.empty())
  {
    auto cur{Q.front()};
    Q.pop();
    for (int i{}; i < 4; i++)
    {
      auto nxt{cur};
      nxt.first += dx[i];
      nxt.second += dy[i];

      if (nxt.first < 0 || nxt.first >= h)
        continue;
      if (nxt.second < 0 || nxt.second >= w)
        continue;

      auto nxtBuildng{&building[nxt.first][nxt.second]};
      if (*nxtBuildng == '*')
        continue;
      if (*nxtBuildng >= 'A' && *nxtBuildng <= 'Z')
        continue;
      if (vis[nxt.first][nxt.second])
        continue;

      if (*nxtBuildng == '$')
      {
        doc++;
        *nxtBuildng = '.';
      }
      else if (*nxtBuildng >= 'a' && *nxtBuildng <= 'z')
        unlock(*nxtBuildng);
      vis[nxt.first][nxt.second] = true;
      visCnt++;
      Q.push({nxt.first, nxt.second});
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  for (int k{}; k < t; k++)
  {
    init();
    cin >> h >> w;
    for (int i{}; i < h; i++)
    {
      string c;
      cin >> c;
      for (int j{}; j < w; j++)
      {
        building[i][j] = c[j];
      }
    }
    cin >> key;
    for (int i{}; i < key.size(); i++)
    {
      if (key[i] == '0')
        break;
      else
        unlock(key[i]);
    }

    // showBuilding();

    for (int i{}; i < h; i++)
    {
      for (int j{}; j < w; j++)
      {
        if ((i == 0 || i == h - 1) || (j == 0 || j == w - 1))
        {
          if (building[i][j] == '.')
          {
            vis[i][j] = true;
            visCnt++;
            Q.push({i, j});
          }
          else if (building[i][j] == '$')
          {
            doc++;
            building[i][j] = '.';
            vis[i][j] = true;
            visCnt++;
            Q.push({i, j});
          }
          else if (building[i][j] >= 'a' && building[i][j] <= 'z')
          {
            unlock(building[i][j]);
            building[i][j] = '.';
            vis[i][j] = true;
            visCnt++;
            Q.push({i, j});
          }
        }
      }
    }
    bfs();
    // showVis();

    int befVisCnt{visCnt};
    while (true)
    {
      for (int i{}; i < h; i++)
      {
        for (int j{}; j < w; j++)
        {
          if (vis[i][j])
          {
            Q.push({i, j});
          }
          else if ((i == 0 || i == h - 1) || (j == 0 || j == w - 1))
          {
            if (building[i][j] == '.')
            {
              vis[i][j] = true;
              visCnt++;
              Q.push({i, j});
            }
          }
        }
      }
      bfs();
      // showVis();
      if (befVisCnt == visCnt)
        break;
      befVisCnt = visCnt;
    }
    cout << doc << "\n";
  }

  return 0;
}