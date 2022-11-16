#include <bits/stdc++.h>

using namespace std;

map<string,vector<string>> m;
map<string,vector<string>> res;
map<string,int> connect;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    for(int i= 0; i< N;i++)
    {
        string s;
        cin >> s;
        connect[s] = 0;
    }
    int M;
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        string s1,s2;
        cin >> s1 >> s2;
        m[s2].push_back(s1);
        connect[s1]++;
    }
    queue<string> q;
    vector<string> temp;
    for(auto c : connect)
    {
        if(!c.second)
        {
            q.push(c.first);
            temp.push_back(c.first);
        }
    }
    cout << temp.size() << '\n';
    for(auto a : temp)
    {
        cout << a << ' ';
    }
    cout << '\n';
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        for(auto d : m[cur])
        {
            connect[d]--;
            if(!connect[d])
            {
                q.push(d);
                res[cur].push_back(d);
            }
        }
    }
    for(auto a : connect)
    {
        cout << a.first << ' ' << res[a.first].size() << ' ';
        sort(res[a.first].begin(), res[a.first].end());
        for(auto x : res[a.first])
            cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
