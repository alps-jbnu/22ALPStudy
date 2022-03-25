#include <bits/stdc++.h>

using namespace std;

int dist[301][301];
bool visited[301][301];
int dx[8] = {1,1,-1,-1,2,2,-2,-2};
int dy[8] = {2,-2,2,-2,1,-1,1,-1};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int TC;
    int l;
    int x,y;
    int destx,desty;
    
    cin>>TC;

    for(int i = 0;i<TC;++i)
    {
        queue<pair<int,int>> Q;
        
        for(int i = 0;i<=300;++i)
        {
            for(int j = 0;j<=300;++j)
            {
                dist[i][j] = -1;
                visited[i][j] = false;
            }
        }

        cin>>l>>x>>y>>destx>>desty;

        visited[x][y] = true;
        dist[x][y] = 0;
        Q.push({x,y});

        while(!Q.empty())
        {
            pair<int,int> now = Q.front();
            Q.pop();

            if(now.first == destx && now.second == desty)
            {
                break;
            }
            for(int dir = 0; dir<8; ++dir)
            {
                int nx = now.first+dx[dir];
                int ny = now.second+dy[dir];

                if(nx < 0 || nx >= l || ny < 0 || ny >= l)
                {
                    continue;
                }
                else if(visited[nx][ny] == false)
                {
                    visited[nx][ny] = true;
                    dist[nx][ny] = dist[now.first][now.second] + 1;
                    Q.push({nx,ny});
                }
            }
        }
        cout<<dist[destx][desty]<<"\n";
    }


    return 0;
}