#include <bits/stdc++.h>

using namespace std;

vector<int> v[10001];
int costime[10001];
int waitime[10001];
int connect[10001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    for(int i = 1; i <= N;i++)
    {
        cin >> costime[i];
        waitime[i] = costime[i];
        int num; cin >> num;
        for(int j = 1; j <= num;j++)
        {
            int x; cin >> x;
            v[i].push_back(x);
            connect[x]++;
        }
    }
    queue<int> q;
    for(int i = 1; i<=N;i++)
        if(!connect[i])
            q.push(i);
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        for(int a : v[cur])
        {
            connect[a]--;
            if(!connect[a])
                q.push(a);
            waitime[a] = max(waitime[a], waitime[cur] + costime[a]);
        }
    }
    int ans = 0;
    for(int i = 1; i <= N;i++)
        ans = max(ans,waitime[i]);
    cout << ans;
    return 0;
}
