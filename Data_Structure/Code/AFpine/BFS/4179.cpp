#include <bits/stdc++.h>

using namespace std;

char board[1001][1001];
int dist[1001][1001];
bool visited[1001][1001];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int R,C;
    string s;
    queue<pair<int,int>> JQ;
    queue<pair<int,int>> FQ;
    int minresult = 100000000;

    cin>>R>>C;

    for(int i = 0 ;i<R;++i)
    {
        cin>>s;
        for(int j = 0;j<C;++j)
        {
            dist[i][j] = 100000000;
            board[i][j] = s[j];
            if(board[i][j] == 'J')
            {
                JQ.push({i,j});
            }
            if(board[i][j] == 'F')
            {
                FQ.push({i,j});
                visited[i][j] = true;
                dist[i][j] = 0;
            }
        }
    }

    
    while(!FQ.empty())
    {
        pair<int,int> now = FQ.front();
        FQ.pop();

        for(int dir = 0; dir<4; ++dir)
        {
            int x = now.first + dx[dir];
            int y = now.second + dy[dir];

            if(x < 0 || x >= R || y < 0 || y >= C)
            {
                continue;
            }
            else if(board[x][y] == '#' || visited[x][y] == true)
            {
                continue;
            }
            else if(board[x][y] == '.' || board[x][y] == 'J' && visited[x][y] == false)
            {
                visited[x][y] = true;
                dist[x][y] = dist[now.first][now.second] + 1;
                FQ.push({x,y});
            }
        }
    }

    for(int i = 0;i<R;++i)
    {
        for(int j = 0;j<C;++j)
        {
            visited[i][j] = false;
        }
    }

    dist[JQ.front().first][JQ.front().second] = 0;
    visited[JQ.front().first][JQ.front().second] = true;
    while(!JQ.empty())
    {
        pair<int,int> now = JQ.front();
        JQ.pop();

        for(int dir = 0; dir<4; ++dir)
        {
            int x = now.first + dx[dir];
            int y = now.second + dy[dir];

            if(x < 0 || x >= R || y < 0 || y >= C)
            {
                continue;
            }
            else if(board[x][y] == '#' || visited[x][y] == true)
            {
                continue;
            }
            else if(board[x][y] == '.' && visited[x][y] == false && dist[x][y] > dist[now.first][now.second] + 1)
            {
                visited[x][y] = true;
                board[x][y] = 'J';
                dist[x][y] = dist[now.first][now.second] + 1;
                JQ.push({x,y});
            }
        }  
    }


    for(int i = 0; i<R; ++i)
    {
        for(int j = 0; j<C; ++j)
        {
            if(board[i][j] == 'J')
            {
                for(int dir = 0; dir<4; ++dir)
                {
                    int x = i + dx[dir];
                    int y = j + dy[dir];
    
                    if(x == -1 || x == R || y == -1 || y == C)
                    {
                        if(minresult > dist[i][j])
                        {
                            minresult = dist[i][j];
                        }
                    }
                }   
            }            
        }
    }

    if(minresult == 100000000)
    {
        cout<<"IMPOSSIBLE";
    }
    else
    {
        cout<<minresult + 1<<"\n";
    }

    // for(int i = 0;i<R;++i)
    // {
    //     for(int j = 0;j<C;++j)
    //     {
    //         cout<<board[i][j];
    //     }
    //     cout<<"\n";
    // }

    return 0;




}