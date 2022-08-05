#include <bits/stdc++.h>

//9328 Key (BFS)

using namespace std;

static const int INF = 1000000000;

char MAP[101][101];
bool visited[101][101];
bool key[26];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int T;
    cin>>T;

    for(int t = 0;t<T;++t)
    {
        queue<pair<int,int>> tempQ;
        queue<pair<int,int>> Q;
        int h,w;
        string s;
        string keys;
        bool change = true;
        int result = 0;

        cin>>h>>w;

        for(int i = 0;i<h;++i)
        {
            cin>>s;
            for(int j = 0;j<w;++j)
            {
                MAP[i][j] = s[j];
            }
        }

        for(int i = 0;i<=100;++i)
        {
            for(int j = 0;j<=100;++j)
            {
                visited[i][j] = false;
            }
        }
        
        for(int i = 0;i<26;++i)
        {
            key[i] = false;
        }

        cin>>keys;

        if(keys != "0")
        {
            for(int i = 0;i<keys.length();++i)
            {
                key[keys[i]-'a'] = true;
            }
        }

        for(int i = 0;i<h;++i)
        {
            for(int j = 0;j<w;++j)
            {
                if(MAP[i][j]>='A' && MAP[i][j] <= 'Z' && key[MAP[i][j]-'A'] == true)
                {
                    MAP[i][j] = '.';
                }
                if((i == 0 || i == h-1 || j == 0 || j == w-1) && MAP[i][j] != '*')
                {
                    tempQ.push({i,j});
                }
            }
        }

        while(change)
        {
            for(int i = 0;i<h;++i)
            {
                for(int j = 0;j<w;++j)
                {
                    visited[i][j] = false;
                }
            }
            result = 0;
            change = false;
            Q = tempQ;

            while(!Q.empty())
            {
                pair<int,int> cur = Q.front();
                Q.pop();
                
                if(visited[cur.first][cur.second] == true)
                {
                    continue;
                }
                visited[cur.first][cur.second] = true;

                if(MAP[cur.first][cur.second] == '$')
                {
                    result++;
                }
                else if(MAP[cur.first][cur.second] >= 'A' && MAP[cur.first][cur.second] <= 'Z')
                {
                    if(key[MAP[cur.first][cur.second]-'A'] == true)
                    {
                        MAP[cur.first][cur.second] = '.';
                    }
                    else
                    {
                        continue;
                    }
                }
                else if(MAP[cur.first][cur.second] >= 'a' && MAP[cur.first][cur.second] <= 'z')
                {
                    key[MAP[cur.first][cur.second]-'a'] = true;
                    MAP[cur.first][cur.second] = '.';
                    change = true;
                }

                for(int dir = 0;dir<4;++dir)
                {
                    int x = cur.first+dx[dir];
                    int y = cur.second+dy[dir];

                    if(x < 0 || x >= h || y < 0 || y >= w)
                    {
                        continue;
                    }
                    if((MAP[x][y] == '.'||(MAP[x][y] >= 'a' && MAP[x][y] <= 'z') || MAP[x][y] == '$') && visited[x][y] == false)
                    {
                        Q.push({x,y});
                    }
                    else if((MAP[x][y] >= 'A' && MAP[x][y] <= 'Z') && key[MAP[x][y]-'A'] == true && visited[x][y] == false)
                    {
                        MAP[x][y] = '.';
                        Q.push({x,y});
                    }
                }
            }
        }

        cout<<result<<'\n';
    }

    return 0;
}