#include <bits/stdc++.h>

using namespace std;

int N, M, t;
bool check[10001];
vector<pair<int,int>> v[10001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<tuple<int,int,int>,
                    vector<tuple<int,int,int>>,
                    greater<tuple<int,int,int>>> pq;
    
    cin >> N >> M >> t;
    for(int i = 0; i < M; i++)
    {
        int A, B, C; cin >> A >> B >> C;
        v[A].push_back(make_pair(C,B));
        v[B].push_back(make_pair(C,A));
    }
    check[1] = true;
    int cnt = 0;
    long long ans = 0;
    long long k = 0;
    for(auto nxt : v[1])
        pq.push(make_tuple(nxt.first,1,nxt.second));
    while(cnt < N - 1)
    {
        int a,b,c; tie(c,a,b) = pq.top(); pq.pop();
        if(check[b]) continue;
        check[b] = true;
        ans += c;
        ans += k;
        k += t;
        cnt++;
        for(auto nxt : v[b])
            if(!check[nxt.second])
                pq.push(make_tuple(nxt.first,b,nxt.second));
    }
    cout << ans;
    return 0;
}
