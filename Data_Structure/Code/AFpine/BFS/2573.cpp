#include <bits/stdc++.h>

using namespace std;

int ice[300][300];
int sub[300][300];
bool visited[300][300];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool separate(int N, int M)
{
    for(int i = 0;i<N;++i)
    {
        for(int j = 0;j<M;++j)
        {
            if(visited[i][j] == false && ice[i][j] != 0)
            {
                return true;
            }
        }
    }
    return false;
}

bool melt(int N, int M)
{
    for(int i = 0;i<N;++i)
    {
        for(int j = 0;j<M;++j)
        {
            if(ice[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

void BFS(pair<int,int> highest, int N, int M)
{
    queue<pair<int,int>> q;
    q.push(highest);
    visited[highest.first][highest.second] = true;
    while(!q.empty())
    {
        pair<int,int> now = q.front();
        int cnt = 0;
        q.pop();

        for(int dir = 0;dir<4;++dir)
        {
            int x = now.first + dx[dir];
            int y = now.second + dy[dir];

            if(x<0 || x >= N || y < 0 || y >= M)
            {
                continue;
            }
            else if(ice[x][y] == 0)
            {
                cnt++;
            }
            else if(ice[x][y] != 0 && visited[x][y] == false)
            {
                visited[x][y] = true;
                q.push({x,y});
            }
        }
        sub[now.first][now.second] = cnt;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


    int N,M;
    int max=0;
    int year = 0;
    pair<int,int> highest;
    

    cin>>N>>M;

    for(int i = 0;i<N;++i)
    {
        for(int j = 0;j<M;++j)
        {
            cin>>ice[i][j];
            if(ice[i][j] > max)
            {
                max = ice[i][j];
                highest = {i,j};
            }
            if(i == 0 || j == 0 || i == N-1 || j == M-1)
            {
                ice[i][j] = 0;
            }
        }
    }
    while(true)
    {
        max = 0;
        BFS(highest,N,M);
        if(separate(N,M) == true)
        {
            break;
        }
        else
        {
            for(int i = 0;i<N;++i)
            {
                for(int j = 0;j<M;++j)
                {
                    ice[i][j] -= sub[i][j];
                    if(ice[i][j] < 0)
                    {
                        ice[i][j] = 0;
                    }
                    if(max < ice[i][j])
                    {
                        max = ice[i][j];
                        highest = {i,j};
                    }
                    visited[i][j] = false;
                    sub[i][j] = 0;
                }
            }
        }
        if(melt(N,M))
        {
            year = 0;
            break;
        }
        ++year;
    }

    cout<<year<<"\n";

    return 0;
}