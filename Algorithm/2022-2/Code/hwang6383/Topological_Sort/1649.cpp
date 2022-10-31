#include <bits/stdc++.h>

using namespace std;

vector<int> v[1001];
set<int> mustVisit;
int visit[1001];
int connect[1001];
int dp[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M; cin >> N >> M;
    for(int i =0; i < M; i++)
    {
        int X, Y;
        cin >> X >> Y;
        v[X].push_back(Y);
        connect[Y]++;
    }
    int A,B,K; cin >> A >> B >> K;
    for(int i = 0; i < K; i++)
    {
        int k;
        cin >> k;
        mustVisit.insert(k);
    }
    dp[A] = 1;
    queue<int> q;
    for(int i = 1; i <= N; i++)
        if(!connect[i]) q.push(i);
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        if(mustVisit.find(cur) != mustVisit.end())
        {
            visit[cur]++;
        }
        for(int nxt : v[cur])
        {
            if(visit[cur] == visit[nxt])
                dp[nxt] += dp[cur];
            else if(visit[nxt] < visit[cur])
            {
                visit[nxt] = visit[cur];
                dp[nxt] = dp[cur];
            }
            connect[nxt]--;
            if(!connect[nxt])
            {
                q.push(nxt);
            }
        }
    }
    if(visit[B] == mustVisit.size())
    {
        cout << dp[B];
    }
    else
    {
        cout << 0;
    }
    return 0;
}
