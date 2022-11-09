#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int n;
string a, b;
queue<pair<string, int>> zeroIndeg;
map<string, vector<string>> adj;
map<string, int> indeg;
vector<pair<string, int>> ans;

bool cmp(const pair<string, int> &a, const pair<string, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i{}; i < n; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[a] += 0;
        indeg[b] += 1;
    }

    for (auto it{indeg.begin()}; it != indeg.end(); it++)
    {
        // cout << (*it).first << " " << (*it).second << "\n";
        if ((*it).second == 0)
            zeroIndeg.push({(*it).first, 0});
    }

    while (!zeroIndeg.empty())
    {
        auto cur{zeroIndeg.front()};
        zeroIndeg.pop();
        ans.push_back(cur);
        for (int i{}; i < adj[cur.first].size(); i++)
        {
            auto nxt{adj[cur.first][i]};
            if (--indeg[nxt] == 0)
                zeroIndeg.push({nxt, cur.second + 1});
        }
    }

    sort(ans.begin(), ans.end(), cmp);
    if (ans.size() == indeg.size())
        for (auto it{ans.begin()}; it != ans.end(); it++)
            cout << (*it).first << "\n";
    else
        cout << -1 << "\n";

    return 0;
}