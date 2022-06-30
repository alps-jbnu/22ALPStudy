#include <bits/stdc++.h>

//5214 (BFS)

using namespace std;

static const int INF = 1000000000;

struct Station
{
    int n;                          //station number(useless)
    vector<int> hypertubeindex;     //hypertube index(number) that contains this station
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
    queue<int> q;                   //BFS queue

    cin>>N>>K>>M;

    vector<vector<int>> hypertube(M);
                                    //vector of hypertube set(if use set, TLE)
    
    for(int i = 0;i<M;++i)
    {
        for(int j = 0;j<K;++j)
        {
            cin>>num;                                       //station number
            hypertube[i].push_back(num);                    //in hypertube set [i] contains station 'num'
            station[num].hypertubeindex.push_back(i);       //in num station, you can use hybertube set [i]
        }
    }

    dist[1] = 1;        //start from station 1
    q.push(1);
    visited[1] = true;

    while(!q.empty())
    {
        int cur = q.front();        //current station number
        q.pop();
        if(cur == N)
        {
            break;
        }
        for(auto x : station[cur].hypertubeindex)
        {//x is index of hypertube set that contains current station
            for(auto h : hypertube[x])
            {//can move other stations of hypertube set [x]
                if(visited[h] == false)
                {
                    visited[h] = true;
                    dist[h] = dist[cur] + 1;
                    q.push(h);
                }
            }
        }
    }

    if(dist[N] != 0)            //or dist[N] != INF (if initialize with INF)
    {
        cout<<dist[N]<<'\n';
    }
    else                        //if you can't approach to station N
    {
        cout<<"-1\n";
    }

    return 0;
}