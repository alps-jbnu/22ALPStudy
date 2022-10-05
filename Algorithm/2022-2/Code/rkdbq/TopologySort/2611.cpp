#define MX 1001
#define node first
#define score second
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, p, q, r;
queue<int> zeroIndeg;
vector<pair<int, int>> adj[MX];
vector<pair<int, int>> adjReverse[MX];
int indeg[MX], total[MX];
vector<int> ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cin >> m;
    for (int i{}; i < m; i++)
    {
        cin >> p >> q >> r;
        adj[p].push_back({q, r});
        adjReverse[q].push_back({p, r});
        indeg[q]++;
    }

    zeroIndeg.push(1);
    bool flag{};
    while (!zeroIndeg.empty())
    {
        auto cur{zeroIndeg.front()};
        zeroIndeg.pop();
        for (int i{}; i < adj[cur].size(); i++)
        {
            if (flag && cur == 1)
                break;
            auto nxt{adj[cur][i]};
            total[nxt.node] = max(total[nxt.node], total[cur] + nxt.score);
            if (--indeg[nxt.node] == 0)
                zeroIndeg.push(nxt.node);
        }
        flag = true;
    }

    cout << total[1] << "\n";
    int cur{1};
    while (total[1])
    {
        for (int i{}; i < adjReverse[cur].size(); i++)
        {
            auto nxt{adjReverse[cur][i]};
            if (total[cur] == nxt.score)
                total[1] = 0;
            if (total[1] - nxt.score == total[nxt.node])
            {
                ans.push_back(nxt.node);
                total[1] -= nxt.score;
                cur = nxt.node;
            }
        }
    }
    ans.insert(ans.begin(), 1);
    ans.push_back(1);
    for (auto it{ans.rbegin()}; it != ans.rend(); it++)
        cout << *it << " ";

    return 0;
}