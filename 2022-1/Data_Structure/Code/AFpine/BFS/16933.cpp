#include <bits/stdc++.h>

using namespace std;

static const int INF = 100000000;

char MAP[1001][1001];               //map
int dist[11][1001][1001];           //distance from start vertex(1,1)
bool visited[11][1001][1001];       
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int result = INF;
    queue<pair<int,int>> q;     //vertex queue
    queue<int> wallq;           //number of current broken wall
    queue<bool> daynight;       //true is day, false is night
    queue<int> distq;           //distance from start vertex
    int N,M,K;
    string s;

    cin>>N>>M>>K;

    for(int i = 1;i<=N;++i)
    {                               //initialization
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
    q.push({1,1});              //start vertex
    wallq.push(0);              //first no broken wall
    daynight.push(true);        //start is day
    distq.push(1);              //start vertex has 1 distance

    while(!q.empty())
    {
        pair<int,int> now = q.front();
        q.pop();
        int nowwall = wallq.front();
        wallq.pop();
        bool nowday = daynight.front();
        daynight.pop();
        int nowdist = distq.front();
        distq.pop();
        
        dist[nowwall][now.first][now.second] = nowdist;
        //distance initialization

        for(int dir = 0;dir<4;++dir)
        {
            int x = now.first + dx[dir];
            int y = now.second + dy[dir];
            
            if(x < 1 || x > N || y < 1 || y > M)
            {
                continue;
            }
            if(MAP[x][y] == '0' && visited[nowwall][x][y] == false)
            {//if (x,y) isn't wall
                visited[nowwall][x][y] = true;
                distq.push(dist[nowwall][now.first][now.second] + 1);
                q.push({x,y});
                wallq.push(nowwall);
                if(nowday == true)
                {//day and night change
                    daynight.push(false);
                }
                else
                {
                    daynight.push(true);
                }
            }
            else if(nowwall < K && MAP[x][y] == '1' && visited[nowwall+1][x][y] == false)
            {//if (x,y) is wall and current status can break wall
                if(nowday == true)
                {
                    visited[nowwall+1][x][y] = true;
                    distq.push(dist[nowwall][now.first][now.second] + 1);
                    q.push({x,y});
                    wallq.push(nowwall+1);
                    daynight.push(false);
                }
                else
                {//if current is night, can't break wall and distance is increase
                    distq.push(dist[nowwall][now.first][now.second] + 1);
                    q.push(now);
                    wallq.push(nowwall);
                    daynight.push(true);
                }
            }
        }
    }

    for(int k = 0;k<=K;++k)
    {  
        if(result > dist[k][N][M])
        {//find minimum distance from (1,1) to (N,M)
            result = dist[k][N][M];
        }
    }

    if(result == INF)
    {//if there is no way to destination, print -1
        cout<<"-1\n";
    }
    else
    {//print minimum distance to destination
        cout<<result<<"\n";
    }
    
    return 0;
}