#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int n, m;
bool G[501][501];
bool visited[501];
int cnt[501];

void bfs()
{
    queue<int> q;
    memset(visited, false, sizeof(visited));
    memset(cnt, -1, sizeof(cnt));

    q.push(1);

    int lcnt = 0;
    while(!q.empty())
    {
        int qsize = q.size();
        for (int qs = 0; qs < qsize; qs++)
        {
            int cur = q.front();
            q.pop();
            if(visited[cur]) continue;
            visited[cur] = true;

            // cout << cur << "\n";
            cnt[cur] = lcnt;
            for (int i = 1; i <= n; i++)
            {
                if(visited[i]) continue;
                if(G[cur][i]) q.push(i);
            }
        }
        lcnt++;
    }
}

void solve()
{
    memset(G, false, sizeof(G));
    cin >> n >> m;
    
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u][v] = true;
        G[v][u] = true;
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << G[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    
    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int a, u, v;
        cin >> a >> u >> v;

        if(a == 1)
        {
            G[u][v] = true;
            G[v][u] = true;
        }
        if(a == 2)
        {
            G[u][v] = false;
            G[v][u] = false;
        }

        bfs();

        for (int i = 1; i <= n; i++)
        {
            cout << cnt[i] << " ";
        }
        cout << "\n";
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();
}