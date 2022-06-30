#include <bits/stdc++.h>

using namespace std;

static const int INF = 100000000;

int chess[201][201];
int dist[31][201][201];
bool visited[31][201][201];
int dx[12] = {1,0,-1,0,1,1,2,2,-1,-1,-2,-2};
int dy[12] = {0,1,0,-1,2,-2,1,-1,2,-2,1,-1};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int result = INF;
    queue<pair<int,int>> monkeyq;
    queue<int> jumpq;
    int W,H,K;

    cin>>K>>W>>H;

    for(int i = 0;i<H;++i)
    {
        for(int j = 0;j<W;++j)
        {
            cin>>chess[i][j];
            for(int k = 0;k<=K;++k)
            {
                dist[k][i][j] = INF;
            }
        }
    }

    visited[0][0][0] = true;
    dist[0][0][0] = 0;
    monkeyq.push({0,0});
    jumpq.push(0);

    while(!monkeyq.empty())
    {   
        pair<int,int> now = monkeyq.front();
        monkeyq.pop();
        int nowjump = jumpq.front();
        jumpq.pop();

        for(int dir = 0;dir<12;++dir)
        {
            int x = now.first + dx[dir];
            int y = now.second + dy[dir];
            
            if(nowjump >= K && dir >= 4)
            {
                break;
            }
            if(x < 0 || x >= H || y < 0 || y >= W)
            {
                continue;
            }
            if(chess[x][y] == 0 && visited[nowjump][x][y] == false && dir < 4)
            {
                visited[nowjump][x][y] = true;
                dist[nowjump][x][y] = dist[nowjump][now.first][now.second] + 1;
                monkeyq.push({x,y});
                jumpq.push(nowjump);
            }
            if(chess[x][y] == 0 && visited[nowjump+1][x][y] == false && dir >= 4)
            {
                visited[nowjump+1][x][y] = true;
                dist[nowjump+1][x][y] = dist[nowjump][now.first][now.second] + 1;
                monkeyq.push({x,y});
                jumpq.push(nowjump+1);
            }
        }
    }

    for(int k = 0;k<=K;++k)
    {  
        if(result > dist[k][H-1][W-1])
        {
            result = dist[k][H-1][W-1];
        }
    }

    if(result == INF)
    {
        cout<<"-1\n";
    }
    else
    {
        cout<<result<<"\n";
    }
    
    return 0;
}