#include <bits/stdc++.h>

//14442 breaking wall 2

using namespace std;

static const int INF = 100000000;

char MAP[1001][1001];
int dist[11][1001][1001];
bool visited[11][1001][1001];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int N,M,K;
    string s;
    queue<pair<int,int>> q;
    queue<int> wallq;
    int result = INF;

    cin>>N>>M>>K;

    for(int i = 1;i<=N;++i)
    {
        cin>>s;
        for(int j = 1;j<=M;++j)
        {
            MAP[i][j] = s[j-1];
            for(int k = 0;k<=K;++k)
            {
                dist[k][i][j] = INF;
            }
        }
    }

    visited[0][1][1] = true;
    dist[0][1][1] = 1;
    q.push({1,1});
    wallq.push(0);
    
    while(!q.empty())
    {
        pair<int,int> cur = q.front();
        int curwall = wallq.front();
        q.pop();
        wallq.pop();

        for(int dir = 0;dir<4;++dir)
        {
            int x = cur.first + dx[dir];
            int y = cur.second + dy[dir];

            if(x<1 || x>N || y<1 || y>M)
            {
                continue;
            }
            else if(visited[curwall][x][y] == false && MAP[x][y] == '0')
            {
                visited[curwall][x][y] = true;
                dist[curwall][x][y] = dist[curwall][cur.first][cur.second] + 1;
                q.push({x,y});
                wallq.push(curwall);
            }
            else if(visited[curwall+1][x][y] == false && MAP[x][y] == '1' && curwall+1 <= K)
            {
                visited[curwall+1][x][y] = true;
                dist[curwall+1][x][y] = dist[curwall][cur.first][cur.second] + 1;
                q.push({x,y});
                wallq.push(curwall+1);
            }
        }
    }

    for(int i = 0;i<=K;++i)
    {
        if(result > dist[i][N][M])
        {
            result = dist[i][N][M];
        }
    }

    if(result == INF)
    {
        cout<<"-1\n";
    }
    else
    {
        cout<<result<<'\n';
    }


    return 0;
}