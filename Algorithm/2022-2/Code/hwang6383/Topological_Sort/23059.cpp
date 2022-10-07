#include <bits/stdc++.h>

using namespace std;

map<string,vector<string>> m;
map<string, int> connect;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        string A, B; cin >> A >> B;
        m[A].push_back(B);
        if(connect.find(A) == connect.end())
            connect[A] = 0;
        if(connect.find(B) == connect.end())
            connect[B] = 1;
        else
            connect[B]++;
    }
    set<string> temp[200001];
    queue<string> q;
    for(auto tmp : connect)
    {
        if(!tmp.second)
        {
            temp[0].insert(tmp.first);
        }
    }
    string tp;
    if(!temp[0].empty())
    {
        for(auto c : temp[0])
            q.push(c);
        tp = *prev(temp[0].end());
    }
    int count = 0;
    int i = 1;
    while(!q.empty())
    {
        count++;
        string cur = q.front(); q.pop();
        for(string a : m[cur])
        {
            connect[a]--;
            if(!connect[a])
            {
                temp[i].insert(a);
            }
        }
        if(tp == cur)
        {
            if(!temp[i].empty())
            {
                tp = *prev(temp[i].end());
                for(auto c : temp[i])
                    q.push(c);
                i++;
            } 
        }
    }
    if(count != m.size())
        cout << -1;
    else
    {
        for(int i = 0; !temp[i].empty(); i++)
        {
            for(auto d : temp[i])
                cout << d << '\n';
        }
    }
    return 0;
}
