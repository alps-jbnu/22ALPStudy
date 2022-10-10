#include <bits/stdc++.h>

using namespace std;

int connect[1001];
int costime[1001];
int waitime[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while(T--)
    {
        vector<int> v[1001];
        int N, K; cin >> N >> K;
        for(int i = 1; i <= N;i++)
            cin >> costime[i];
        for(int i = 1; i<=K;i++)
        {
            int X,Y; cin >> X >> Y;
            v[X].push_back(Y);
            connect[Y]++;
        }
        queue<int> q;
        for(int i = 1; i <= N; i++)
            if(!connect[i])
            {
                q.push(i);
                waitime[i] = costime[i];
            }
        int W; cin >> W;
        while(!q.empty())
        {
            int cur = q.front(); q.pop();
            if(cur == W)
                break;
            for(int nxt : v[cur])
            {
                connect[nxt]--;
                if(!connect[nxt])
                    q.push(nxt);
                waitime[nxt] = max(waitime[nxt], waitime[cur] + costime[nxt]);
            }
        }
        cout << waitime[W] << '\n';
        fill(connect,connect+N+1,0);
        fill(costime,costime+N+1,0);
        fill(waitime,waitime+N+1,0);
    }
    return 0;
}
