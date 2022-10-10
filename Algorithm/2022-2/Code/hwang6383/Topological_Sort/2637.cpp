#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> v[101];
int need[101][101];
int connect[101];
set<int> ans;

void addneed(int x, int y, int k)
{
    if(ans.find(y) != ans.end())
        need[x][y] += k;
    else
        for(int i =1; i <= 100; i++)
            need[x][i] += need[y][i] * k;
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M; cin >> N >> M;
    for(int i = 1; i <= M;i++)
    {
        int X,Y,K; cin >> X >> Y >> K;
        v[Y].push_back({X,K});
        connect[X]++;
    }
    queue<int> q;
    for(int i = 1; i < N; i++)
        if(!connect[i])
        {
            q.push(i);
            ans.insert(i);
        }
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        for(auto nxt : v[cur])
        {
            connect[nxt.first]--;
            if(!connect[nxt.first])
                q.push(nxt.first);
            addneed(nxt.first,cur,nxt.second);
        }
    }
    for(auto a : ans)
        cout << a << ' ' << need[N][a] << '\n';
    return 0;
}
