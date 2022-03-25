#include <bits/stdc++.h>

using namespace std;

static const int INF = 100000000;

struct hut
{
    vector<int> edge;
};

int dist[20001];
bool visited[20001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N,M;
    int A,B;
    queue<int> q;
    int cnt = 0;
    int mostfar = 0;
    int mostfarhut = 0;

    cin>>N>>M;

    vector<hut> v(N+1);

    for(int i = 0;i<M;++i)
    {
        cin>>A>>B;
        v[A].edge.push_back(B);
        v[B].edge.push_back(A);
    }
    for(int i = 1;i<=N;++i)
    {
        dist[i] = INF;
    }


    q.push(1);
    visited[1] = true;
    dist[1] = 0;

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        for(auto x : v[now].edge)
        {
            if(visited[x] == false)
            {
                dist[x] = dist[now] + 1;
                visited[x] = true;
                q.push(x);
            }
        }
    }

    for(int i = 1;i<=N;++i)
    {
        if(dist[i] > mostfar)
        {
            mostfar = dist[i];
            mostfarhut = i;
            cnt = 1;
        }
        else if(dist[i] == mostfar)
        {
            ++cnt;
        }
    }

    cout<<mostfarhut<<" "<<mostfar<<" "<<cnt<<"\n";

    return 0;
}