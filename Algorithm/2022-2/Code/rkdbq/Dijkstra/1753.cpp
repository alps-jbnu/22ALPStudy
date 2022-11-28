#define MX_V 1001
#define MX_E 2000001

#define dis first
#define node second
#define pii pair<int, int>

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class nextNode
{
public:
    int to;
    int w;
    nextNode(int to, int w)
    {
        this->to = to;
        this->w = w;
    }
};

int V, E, K;
vector<nextNode> adj[MX_V];
priority_queue<pii, vector<pii>, greater<pii>> PQ;
priority_queue<int> ans[MX_V];

void show()
{
    for (int i{1}; i <= V; i++)
    {
        if(ans[i].size() < K) cout<<-1<<'\n';
        else cout<<ans[i].top()<<'\n';
    }
}

void dijkstra() {
    ans[1].push(0);
    PQ.push({0, 1});
    while (!PQ.empty())
    {
        auto cur{PQ.top()};
        PQ.pop();

        for (int i{}; i < adj[cur.node].size(); i++)
        {
            auto nxt{adj[cur.node][i]};
            if(ans[nxt.to].size() < K) {
                ans[nxt.to].push(nxt.w + cur.dis);
                PQ.push({nxt.w + cur.dis, nxt.to});
            }
            else {
                if(nxt.w + cur.dis < ans[nxt.to].top()) {
                    ans[nxt.to].pop();
                    ans[nxt.to].push(nxt.w + cur.dis);
                    PQ.push({nxt.w + cur.dis, nxt.to});
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> V >> E;
    cin >> K;

    for (int i{}; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(nextNode(v, w));
    }

    dijkstra();

    show();

    return 0;
}