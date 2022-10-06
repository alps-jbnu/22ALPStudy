#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> v[1001];
int connect[1001];
int score[1001];
int his[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M; cin >> N >> M;
    for(int i = 0; i < M;i++)
    {
        int p,q,r;
        cin >> p >> q >> r;
        v[p].push_back({q,r});
        connect[q]++;
    }
    queue<int> que;
    que.push(1);
    while(!que.empty())
    {
        int cur = que.front(); que.pop();
        for(pair<int,int> nxt : v[cur])
        {
            if(score[nxt.first] < score[cur] + nxt.second)
            {
                score[nxt.first] = score[cur] + nxt.second;
                his[nxt.first] = cur;
            }
            connect[nxt.first]--;
            if(!connect[nxt.first] && nxt.first != 1)
                que.push(nxt.first);
        }
    }
    cout << score[1] << '\n';
    cout << 1 << ' ';
    vector<int> vec;
    for(int i = 1; his[i] != 1; i = his[i])
    {
        vec.push_back(his[i]);
    }
    for(int i = vec.size()-1; i>=0;i--)
        cout << vec[i] << ' ';
    cout << 1;
    return 0;
}
