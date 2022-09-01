#define MX 1501
#define INT_MAX 2000000001

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Swan
{
public:
  int x;
  int y;
  bool name;
};

int r, c;
char lake[MX][MX];
int dayCnt{1};
int ans{INT_MAX};

int dx[4]{1, -1, 0, 0};
int dy[4]{0, 0, 1, -1};
bool visWater[MX][MX];
int visSwan[MX][MX][2];
queue<pair<int, int>> water;
queue<pair<int, int>> nxtStWater;
queue<Swan> swan[2];
queue<Swan> nxtSt[2];

void showLake()
{
  cout << "\n";
  for (int i{}; i < r; i++)
  {
    for (int j{}; j < c; j++)
    {
      cout << lake[i][j];
    }
    cout << "\n";
  }
  cout << "\n";
}

void showSwanA()
{
  cout << "\n";
  for (int i{}; i < r; i++)
  {
    for (int j{}; j < c; j++)
    {
      cout << visSwan[i][j][0];
    }
    cout << "\n";
  }
  cout << "\n";
}

void showSwanB()
{
  cout << "\n";
  for (int i{}; i < r; i++)
  {
    for (int j{}; j < c; j++)
    {
      cout << visSwan[i][j][1];
    }
    cout << "\n";
  }
  cout << "\n";
}

void melt()
{
  while (!water.empty())
  {
    auto cur{water.front()};
    water.pop();
    for (int i{}; i < 4; i++)
    {
      auto nxt{cur};
      nxt.first += dx[i];
      nxt.second += dy[i];

      if (nxt.first < 0 || nxt.first >= r)
        continue;
      if (nxt.second < 0 || nxt.second >= c)
        continue;
      if (visWater[nxt.first][nxt.second])
        continue;
      if (lake[nxt.first][nxt.second] == 'X')
      {
        visWater[nxt.first][nxt.second] = true;
        nxtStWater.push(nxt);
        lake[nxt.first][nxt.second] = '.';
      }
    }
  }
}

void moveSwan()
{
  for (int j{}; j < 2; j++)
  {
    while (!swan[j].empty())
    {
      auto cur{swan[j].front()};
      swan[j].pop();
      for (int i{}; i < 4; i++)
      {
        auto nxt{cur};
        nxt.x += dx[i];
        nxt.y += dy[i];

        if (nxt.x < 0 || nxt.x >= r)
          continue;
        if (nxt.y < 0 || nxt.y >= c)
          continue;
        if (visSwan[nxt.x][nxt.y][nxt.name])
          continue;
        if (lake[nxt.x][nxt.y] == 'X')
        {
          nxtSt[j].push(cur);
          continue;
        }
        visSwan[nxt.x][nxt.y][nxt.name] = dayCnt;
        swan[j].push(nxt);
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> r >> c;
  char name{'A'};
  for (int i{}; i < r; i++)
  {
    string C;
    cin >> C;
    for (int j{}; j < c; j++)
    {
      if (C[j] != 'X')
      {
        visWater[i][j] = true;
        nxtStWater.push({i, j});
        if (C[j] == 'L')
        {
          C[j] = name++;
          visSwan[i][j][C[j] - 'A'] = dayCnt;
          Swan st;
          st.x = i;
          st.y = j;
          st.name = C[j] - 'A';
          nxtSt[C[j] - 'A'].push(st);
        }
      }
      lake[i][j] = C[j];
    }
  }
  // showLake();

  while (!nxtSt[0].empty() || !nxtSt[1].empty())
  {
    for (int i{}; i < 2; i++)
    {
      while (!nxtSt[i].empty())
      {
        swan[i].push(nxtSt[i].front());
        nxtSt[i].pop();
      }
    }
    moveSwan();
    // showSwanA();
    // showSwanB();

    while (!nxtStWater.empty())
    {
      water.push(nxtStWater.front());
      nxtStWater.pop();
    }
    melt();
    // showLake();

    dayCnt++;
  }

  for (int i{}; i < r; i++)
  {
    for (int j{}; j < c; j++)
    {
      int visSwanMax{max(visSwan[i][j][0], visSwan[i][j][1])};
      ans = min(ans, visSwanMax);
    }
  }
  cout << ans - 1;

  return 0;
}