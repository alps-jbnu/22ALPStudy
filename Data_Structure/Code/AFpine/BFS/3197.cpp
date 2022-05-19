#include <bits/stdc++.h>

// 3197 백조의 호수

// update 220407

using namespace std;

static const int INF = 1e9+1;

char lake[1500][1500];
int melttime[1500][1500];
int swandist[1500][1500];
bool visited[1500][1500];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int R,C;
    string s;
    queue<pair<int,int>> waterQ;
    queue<int> melttimeQ;
    queue<pair<int,int>> swanQ;
    queue<pair<int,int>> nswanQ;
    pair<int,int> swan1{-1,-1}, swan2{-1,-1};
    int resultday = 0;
    bool meet = false;

    cin>>R>>C;

    for(int i = 0;i<R;++i)
    {
        for(int j = 0;j<C;++j)
        {
            melttime[i][j] = INF;
            swandist[i][j] = INF;
        }
    }

    for(int i = 0;i<R;++i)
    {
        cin>>s;
        for(int j = 0;j<C;++j)
        {
            lake[i][j] = s[j];
            if(lake[i][j] == '.')
            {
                waterQ.push({i,j});
                melttimeQ.push(1);
                melttime[i][j] = 0;
            }
            else if(lake[i][j] == 'L')
            {
                waterQ.push({i,j});
                melttimeQ.push(1);
                melttime[i][j] = 0;
                if(swan1 == pair<int,int>(-1,-1))
                {
                    swan1 = {i,j};
                }
                else
                {
                    swan2 = {i,j};
                }
            }
        }
    }

    while(!waterQ.empty())
    {
        pair<int,int>cur = waterQ.front();
        int curmelttime = melttimeQ.front();
        melttimeQ.pop();
        waterQ.pop();

        for(int dir=0;dir<4;++dir)
        {
            int x = cur.first+dx[dir];
            int y = cur.second+dy[dir];
            if(x<0 || x>=R || y<0 || y>= C)
            {
                continue;
            }
            if(lake[x][y] == 'X' && melttime[x][y] > curmelttime)
            {
                melttime[x][y] = curmelttime;
                waterQ.push({x,y});
                melttimeQ.push(curmelttime+1);
            }
        }
    }

    swanQ.push(swan1);
    swandist[swan1.first][swan1.second] = 0;

    while(true)
    {
        while(!swanQ.empty())
        {
            pair<int,int>cur = swanQ.front();
            swanQ.pop();
            if(cur == swan2)
            {
                meet = true;
                break;
            }
            for(int dir = 0;dir<4;++dir)
            {
                int x = cur.first + dx[dir];
                int y = cur.second + dy[dir];

                if(x < 0 || x >= R || y < 0 || y >= C)
                {
                    continue;
                }
                if(visited[x][y] == false && melttime[x][y] <= resultday)
                {
                    visited[x][y] = true;
                    swanQ.push({x,y});
                }
                else if(visited[x][y] == false && melttime[x][y] == resultday + 1)
                {
                    visited[x][y] = true;
                    nswanQ.push({x,y});
                }
            }
        }
        if(meet)
        {
            break;
        }
        while(!nswanQ.empty())
        {
            swanQ.push(nswanQ.front());
            nswanQ.pop();
        }
        resultday++;
    }

    cout<<resultday<<'\n';


	return 0;
}