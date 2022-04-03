#include <bits/stdc++.h>

//5214 

using namespace std;

static const int INF = 100000000;

struct Station
{
    int n;
    vector<int> hypertubeindex;
};

Station station[100001];
bool visited[100001];
int dist[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int N,K,M;
    int num;
    queue<int> q;

    cin>>N>>K>>M;

    vector<vector<int>> hypertube(M);
    
    for(int i = 0;i<M;++i)
    {
        for(int j = 0;j<K;++j)
        {
            cin>>num;
            hypertube[i].push_back(num);
            station[num].hypertubeindex.push_back(i);
        }
    }

    dist[1] = 1;
    q.push(1);
    visited[1] = true;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        if(cur == N)
        {
            break;
        }
        for(auto x : station[cur].hypertubeindex)
        {
            for(auto h : hypertube[x])
            {
                if(visited[h] == false)
                {
                    visited[h] = true;
                    dist[h] = dist[cur] + 1;
                    q.push(h);
                }
            }
        }
    }

    if(dist[N] != 0)
    {
        cout<<dist[N]<<'\n';
    }
    else
    {
        cout<<"-1\n";
    }

    return 0;
}