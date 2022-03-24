//이게 왜 되냐? 디버깅 한 번도 안해봤는데
#include <bits/stdc++.h>

using namespace std;

static const int INF = 100000000;

int sea[100][100];          //whole sea (whole map)
int dist[100][100];         //distance vertex to other vertex
int island[101][101];       //island number which is bordered with sea(vertex)
bool visited[100][100];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N;
    int maxresult = INF;
    queue<pair<int,int>> seaq;  //sea bordered with island
    queue<pair<int,int>> islandq;   //island vertex queue

    cin>>N;

    for(int i = 0;i<N;++i)
    {
        for(int j = 0;j<N;++j)
        {
            cin>>sea[i][j];
            if(sea[i][j] == 1)
            {
                islandq.push({i,j});
            }
        }
    }

    int num = 0;
    while(!islandq.empty())
    {//different islands has different number (increase from 1)
        queue<pair<int,int>> q;
        pair<int,int> cur = islandq.front();
        islandq.pop();

        if(visited[cur.first][cur.second] == true)
        {
            continue;
        }
        
        ++num;
        sea[cur.first][cur.second] = num;
        visited[cur.first][cur.second] = true;
        q.push(cur);

        while(!q.empty())
        {
            pair<int,int> now = q.front();
            q.pop();
            for(int dir = 0;dir<4;++dir)
            {
                int x = now.first + dx[dir];
                int y = now.second + dy[dir];

                if(x<0 || x >= N || y < 0 || y >= N)
                {
                    continue;
                }
                else if(sea[x][y] == 1 && visited[x][y] == false)
                {
                    visited[x][y] = true;
                    sea[x][y] = num;
                    q.push({x,y});
                }
            }
        }
    }

    //push sea vertex which bordered with island to seaq
    for(int i = 0;i<N;++i)
    {
        for(int j = 0;j<N;++j)
        {
            if(sea[i][j] != 0)
            {
                continue;
            }
            bool flag = false;
            for(int dir = 0;dir<4;++dir)
            {
                int x = i+dx[dir];
                int y = j+dy[dir];
                if(x < 0 || x >= N || y < 0 || y >= N)
                {
                    continue;
                }
                else if(sea[x][y] != 0)
                {
                    flag = true;
                    island[i][j] = sea[x][y];
                    break;
                }
            }
            if(flag)
            {
                seaq.push({i,j});
            }
        }
    }

    while(!seaq.empty())
    {// BFS until start vertex(sea) reaches to other vertex(sea) is bordered other island 
        for(int i = 0;i<N;++i)
        {
            for(int j = 0;j<N;++j)
            {
                visited[i][j] = false;
                dist[i][j] = INF;
            }
        }
        int islandnum;
        int result = INF;
        queue<pair<int,int>> q;
        pair<int,int> cur = seaq.front();
        seaq.pop();
        
        islandnum = island[cur.first][cur.second];
        visited[cur.first][cur.second] = true;
        dist[cur.first][cur.second] = 1;
        q.push(cur);

        while(!q.empty())
        {
            pair<int,int> now = q.front();
            q.pop();

            for(int dir = 0;dir<4;++dir)
            {
                int x = now.first + dx[dir];
                int y = now.second + dy[dir];

                if(x<0 || x >= N || y < 0 || y >= N)
                {
                    continue;
                }
                else if(sea[x][y] == 0 && visited[x][y] == false)
                {
                    visited[x][y] = true;
                    dist[x][y] = dist[now.first][now.second] + 1;
                    q.push({x,y});
                }
                else if(sea[x][y] != 0 && sea[x][y] != islandnum)
                {
                    result = dist[now.first][now.second];
                }
            }
            if(result != INF)
            {
                break;
            }
        }
        if(maxresult > result)
        {
            maxresult = result;
        }
    }

    cout<<maxresult<<"\n";

    return 0;
}