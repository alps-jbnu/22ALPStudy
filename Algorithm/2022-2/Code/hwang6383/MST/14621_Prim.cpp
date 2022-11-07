#include <bits/stdc++.h>

using namespace std;

int N, M;
bool check[1001];
vector<pair<int,int>> vec[1001];
bool sc[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<tuple<int,int,int>,
                    vector<tuple<int,int,int>>,
                    greater<tuple<int,int,int>>> pq;
    
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        char sex; cin >> sex;
        if(sex == 'M')
            sc[i] = true;
    }
    for(int i = 1; i <= M; i++)
    {
        int u,v,d; cin >> u >> v >> d;
        if(!(sc[u] ^ sc[v])) continue;
        vec[u].push_back(make_pair(d,v));
        vec[v].push_back(make_pair(d,u));
    }
    check[1] =true;
    int cnt = 0;
    int ans = 0;
    for(auto nxt : vec[1])
        pq.push(make_tuple(nxt.first, 1, nxt.second));
    while(cnt < N - 1 && !pq.empty())
    {
        int a,b,c; tie(c,a,b) = pq.top(); pq.pop();
        if(check[b]) continue;
        check[b] = true;
        ans += c;
        cnt++;
        for(auto nxt : vec[b])
        {
            if(!check[nxt.second])
                pq.push(make_tuple(nxt.first, b,nxt.second));
        }
    }
    if(cnt == N - 1)
        cout << ans;
    else
        cout << -1;
    return 0;
}
