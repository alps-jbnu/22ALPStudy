#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector<pair<int, int> > v[1001];
int p, q, r;
int n, m;
int arr[1001];
int dp[1001];
int dp2[1001];
int node, mx = -1;
int ans;

void function()
{
    stack<int> s;
    queue<int> q;
    
    for(int i = 1; i <= n; i++)
    {
        if (!arr[i])
        {
            q.push(i);
        }
    }
    
    while (!q.empty())
    {
        int x = q.front();
        
        q.pop();
        
        for (int i = 0; i < v[x].size(); i++)
        {
            int y = v[x][i].first;
            
            if (dp[y] < dp[x] + v[x][i].second)
            {
                dp[y] = dp[x] + v[x][i].second;
                dp2[y] = x;
            }
            
            if (!--arr[y])
            {
                q.push(y);
            }
        }
    }
    
    node = dp2[1];
    
    while (node != 1)
    {
        s.push(node);
        node = dp2[node];
    }
    
    cout << dp[1] << "\n";
    
    cout << 1 << " ";
    
    while (s.size())
    {
        cout << s.top() << " ";
        s.pop();
    }
    
    cout << 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    cin >> m;
    
    if (n == 1)
    {
        cout << 0 << "\n" << 1;
        return 0;
    }
    
    for (int i = 1; i <= m; i++)
    {
        cin >> p >> q >> r;
        if(p==1)
        {
            dp[q] = r;
            dp2[q] = 1;
            continue;
        }
        v[p].push_back({q, r});
        arr[q]++;
    }
    
    function();
}
