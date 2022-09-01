#define MX_M 100001  // number of used password
#define MX_N 1048576 // maximum password

#include <iostream>
#include <algorithm>
#include <bitset>
#include <queue>
#include <unordered_map>
using namespace std;

int n, m;
// string p[MX_M];
int ans;

int safety[MX_N];
// string binaryOf[MX_N];
// unordered_map<string, int> decimalOf;
// queue<string> Q;
queue<int> Q;

// string toBinary(int n)
// {
//   bitset<20> r(n);
//   return r.to_string();
// }

// void init()
// {
//   for (int i{}; i < MX_N; i++)
//   {
//     safety[i] = -1;

//     string bi{toBinary(i)};
//     binaryOf[i] = bi;
//     decimalOf[bi] = i;
//   }
// }

void bfs()
{
  while (!Q.empty())
  {
    auto cur{Q.front()};
    Q.pop();
    for (int i{}; i < 20; i++)
    {
      auto nxt{cur ^ (1 << i)};
      // if (nxt[i] == '0')
      //   nxt[i] = '1';
      // else
      //   nxt[i] = '0';

      // if (decimalOf[nxt] > n)
      //   continue;
      // if (safety[decimalOf[nxt]] != -1)
      //   continue;
      if (nxt > n)
        continue;
      if (safety[nxt] != -1)
        continue;
      // safety[decimalOf[nxt]] = safety[decimalOf[cur]] + 1;
      safety[nxt] = safety[cur] + 1;
      Q.push(nxt);
      // if (ans < safety[decimalOf[nxt]])
      //   ans = safety[decimalOf[nxt]];
      if (ans < safety[nxt])
        ans = safety[nxt];
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // init();
  fill(safety, safety + MX_N, -1);
  cin >> n;
  cin >> m;
  for (int i{}; i < m; i++)
  {
    int d{};
    cin >> d;
    // p[i] = binaryOf[d];
    safety[d] = 0;
    // Q.push(p[i]);
    Q.push(d);
  }
  bfs();
  cout << ans;
  return 0;
}