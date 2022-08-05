#define INT_MAX 2000000000

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int stu[1001][1001];
int fir[1001];
int cnt[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int ans = INT_MAX;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> stu[i][j];
    }
  }
  for (int i = 0; i < n; i++)
  {
    sort(stu[i], stu[i] + m);
    pq.push({stu[i][0], i});
    fir[i] = stu[i][0];
  }

  int maxEle = *max_element(fir, fir + n);

  while (true)
  {
    pair<int, int> pqTop = pq.top();
    // cout<<*maxEle<<" "<<*minEle<<"\n";
    if (cnt[pqTop.second] == n)
      break;

    ans = min(ans, maxEle - pqTop.first);
    int nxt = stu[pqTop.second][++cnt[pqTop.second]];
    maxEle = max(maxEle, nxt);
    pq.pop();
    pq.push({nxt, pqTop.second});
  }

  cout << ans << "\n";

  return 0;
}