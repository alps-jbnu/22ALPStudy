#include <iostream>
#include <queue>
using namespace std;

class Player
{
public:
  int x;
  int y;
  int num;
  int s;
};

int n, m, p;
int S[10];
char gameboard[1001][1001];

int dx[4]{1, -1, 0, 0};
int dy[4]{0, 0, 1, -1};
int vis[1001][1001];
queue<Player> Q;
queue<Player> nxtSt[10];

int ans[10];

void show()
{
  for (int i{}; i < n; i++)
  {
    for (int j{}; j < m; j++)
    {
      cout << vis[i][j];
    }
    cout << "\n";
  }
}

void bfs()
{
  while (!Q.empty())
  {
    Player cur{Q.front()};
    Q.pop();
    for (int i{}; i < 4; i++)
    {
      Player nxt{cur};
      nxt.x += dx[i];
      nxt.y += dy[i];
      nxt.s += 1;

      if (nxt.x < 0 || nxt.x >= n)
        continue;
      if (nxt.y < 0 || nxt.y >= m)
        continue;
      if (nxt.s > S[nxt.num])
        continue;
      if (vis[nxt.x][nxt.y])
        continue;
      if (gameboard[nxt.x][nxt.y] != '.')
        continue;

      vis[nxt.x][nxt.y] = nxt.num;
      if (nxt.s == S[nxt.num])
      {
        nxt.s = 0;
        nxtSt[nxt.num].push(nxt);
      }
      else
      {
        Q.push(nxt);
      }

      // cout<<"cur "<<cur.x<<" "<<cur.y<<" "<<cur.s<<" "<<cur.num<<"\n";
      // cout<<"nxt "<<nxt.x<<" "<<nxt.y<<" "<<nxt.s<<" "<<nxt.num<<"\n";
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> p;
  for (int i{1}; i <= p; i++)
    cin >> S[i];
  for (int i{}; i < n; i++)
  {
    string c;
    cin >> c;
    for (int j{}; j < m; j++)
    {
      gameboard[i][j] = c[j];
    }
  }
  for (int j{}; j < n; j++)
  {
    for (int k{}; k < m; k++)
    {
      int num{gameboard[j][k] - '0'};
      if (num >= 1 && num <= 9)
      {
        Player st;
        st.x = j;
        st.y = k;
        st.num = num;
        st.s = 0;
        vis[st.x][st.y] = st.num;
        nxtSt[num].push(st);
      }
    }
  }
  while (true)
  {
    bool isAllEmpty{true};
    for (int i{1}; i <= p; i++)
    {
      if (!nxtSt[i].empty())
        isAllEmpty = false;
    }
    if (isAllEmpty)
      break;

    for (int i{1}; i <= p; i++)
    {
      while (!nxtSt[i].empty())
      {
        Player st{nxtSt[i].front()};
        Q.push(st);
        nxtSt[i].pop();
      }
      bfs();
    }
  }
  for (int i{}; i < n; i++)
  {
    for (int j{}; j < m; j++)
    {
      int cur{vis[i][j]};
      ans[cur]++;
    }
  }
  // show();
  for (int i{1}; i <= p; i++)
  {
    cout << ans[i] << " ";
  }

  return 0;
}