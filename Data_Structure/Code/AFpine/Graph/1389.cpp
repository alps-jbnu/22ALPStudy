#include <bits/stdc++.h>

using namespace std;

static const int INF = 100000000;

int dist[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N,M;
    int n1,n2;
    int sum = 0;
    int minimum = INF;
    int kevinbacon=0;

    cin>>N>>M;

    for(int i = 1;i<=N;++i)
    {
        for(int j = 1;j<=N;++j)
        {
            if(i==j)
            {
                dist[i][j] = 0;
            }
            else
            {
                dist[i][j] = INF;
            }
        }
    }

    for(int i = 1;i<=M;++i)
    {
        cin>>n1>>n2;
        dist[n1][n2] = 1;
        dist[n2][n1] = 1;
    }



    for(int k = 1;k<=N;++k)
    {
        for(int i = 1;i<=N;++i)
        {
            for(int j = 1;j<=N;++j)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for(int i = 1;i<=N;++i)
    {
        sum = 0;
        for(int j = 1;j<=N;++j)
        {
            sum += dist[i][j];
        }
        if(minimum > sum)
        {
            minimum = sum;
            kevinbacon = i;
        }
    }

    cout<<kevinbacon<<"\n";


    return 0;
}