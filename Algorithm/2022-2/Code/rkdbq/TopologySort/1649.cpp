#define MX 1001
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int a, b, k;
int c[MX], indeg[MX];
vector<int> adj[MX];
queue<int> zeroIndeg;
int cnt[MX], val[MX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i{}; i < m; i++)
    {
        int st, en;
        cin >> st >> en;
        adj[st].push_back(en);
        indeg[en] += 1;
    }

    cin >> a >> b >> k;
    for (int i{}; i < k; i++)
    {
        int num{};
        cin >> num;
        c[num] = true;
    }

    val[a] = 1;
    // zeroIndeg.push(a);
    for (int i{1}; i <= n; i++)
        if (!indeg[i])
            zeroIndeg.push(i);

    while (!zeroIndeg.empty())
    {
        auto cur{zeroIndeg.front()};
        zeroIndeg.pop();
        if (c[cur])
            cnt[cur]++;
        for (int i{}; i < adj[cur].size(); i++)
        {
            auto nxt{adj[cur][i]};
            if (cnt[cur] == cnt[nxt])
                val[nxt] += val[cur];
            else if (cnt[cur] > cnt[nxt])
            {
                val[nxt] = val[cur];
                cnt[nxt] = cnt[cur];
            }
            if (--indeg[nxt] == 0)
                zeroIndeg.push(nxt);
        }
    }

    // for (int i{1}; i <= n; i++)
    //     cout << val[i] << "\n";
    if (cnt[b] != k)
        val[b] = 0;
    cout << val[b];

    return 0;
}