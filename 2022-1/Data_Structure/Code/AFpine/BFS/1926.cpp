#include <bits/stdc++.h>

using namespace std;

int board[501][501];
bool visited[501][501];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n,m;
    int paintcnt = 0;
    int maxarea = 0;
    int nowarea = 0;
    queue<pair<int,int>> Q;

    cin>>n>>m;

    for(int i = 0;i<n;++i)
    {
        for(int j = 0;j<m;++j)
        {
            cin>>board[i][j];
        }
    }

    for(int i = 0;i<n;++i)
    {
        for(int j = 0;j<m;++j)
        {
            if(board[i][j] == 1 && visited[i][j] == false)
            {
                paintcnt++;
                nowarea = 1;
                Q.push({i,j});
                visited[i][j] = true;
                while(!Q.empty())
                {
                    pair<int,int> now = Q.front();
                    Q.pop();
                    for(int dir = 0; dir<4; ++dir)
                    {
                        int x = now.first + dx[dir];
                        int y = now.second + dy[dir];
                        if(x < 0 || x >= n || y < 0 || y >= m)
                        {
                            continue;
                        }
                        else if(board[x][y] == 1 && visited[x][y] == false)
                        {
                            visited[x][y] = true;
                            Q.push({x,y});
                            ++nowarea;
                        }
                    }
                }
                if(maxarea < nowarea)
                {
                    maxarea = nowarea;
                }
            }
        }
    }
    
    cout<<paintcnt<<"\n"<<maxarea<<"\n";

    return 0;
}