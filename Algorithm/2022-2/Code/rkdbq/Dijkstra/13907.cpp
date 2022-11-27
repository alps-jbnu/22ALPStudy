#define MX_N 1001
#define INF 12345678910
#define pii pair<int, int>

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, K;
int S, D;

class Node
{
public:
    int first;
    int second;
    int count;
    Node(int f, int s, int c)
    {
        first = f;
        second = s;
        count = c;
    }
};

struct cmp
{
    bool operator()(Node &a, Node &b)
    {
        return a.first > b.first;
    }
};

priority_queue<Node, vector<Node>, cmp> PQ;
vector<pii> adj[MX_N];
vector<long long> tax;
long long ans[MX_N][MX_N];

void init(int start)
{
    for (int i{}; i < MX_N; i++)
        for (int j{}; j < MX_N; j++)
        {
            ans[i][j] = INF;
        }
    // for (int i{}; i < MX_N; i++)
        ans[start][0] = 0;
}

void show()
{
    for (int i{}; i < tax.size(); i++)
    {
        long long cost{INF};
        for (int j{1}; j <= N; j++)
        {
            cost = min(cost, ans[D][j] + j * tax[i]);
        }
        cout << cost << '\n';
    }
    // for(int i{1}; i<=N; i++) {
    //     for(int j{1}; j<=N; j++) {
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
}

void dijkstra(int start)
{
    init(start);

    PQ.push(Node(0, start, 0));
    while (!PQ.empty())
    {
        auto cur{PQ.top()};
        PQ.pop();

        if (cur.first > ans[cur.second][cur.count])
            continue;
        if (cur.count > N)
            continue;
        for (int i{}; i < adj[cur.second].size(); i++)
        {
            auto nxt{adj[cur.second][i]};
            
            if (nxt.second + cur.first < ans[nxt.first][cur.count + 1])
            {
                ans[nxt.first][cur.count + 1] = nxt.second + cur.first;
                PQ.push(Node(ans[nxt.first][cur.count + 1], nxt.first, cur.count + 1));
            }
        }
    }

    show();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    cin >> S >> D;

    for (int i{}; i < M; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    tax.push_back(0);
    for (int i{1}; i <= K; i++)
    {
        int p;
        cin >> p;
        tax.push_back(p);
        tax[i] += tax[i - 1];
    }

    dijkstra(S);

    return 0;
}