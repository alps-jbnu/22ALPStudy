#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void bfs(int n, vector<vector<int>>& adj)
{
    queue<pii> q;
    q.push({1, 0});
    vector<int> ans(n+1, -1);
    ans[1] = 0;
    while(!q.empty())
    {
        int curr = q.front().first;
        int cnt = q.front().second;
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(adj[curr][i] && ans[i] == -1)
            {
                ans[i] = cnt+1;
                q.push({i, cnt+1});
            }
        }
    }

    for(int i=1;i<=n;i++)
        cout << ans[i] << ' ';
    cout << endl;
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1, vector<int>(n+1, 0));
    int a, b;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    int q;
    cin >> q;
    int k;
    while(q--)
    {
        cin >> k >> a >> b;
        if(k == 1) adj[a][b] = adj[b][a] = 1;
        else adj[a][b] = adj[b][a] = 0;
        bfs(n, adj);
    }

	return 0;
}