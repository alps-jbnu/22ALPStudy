#include <bits/stdc++.h>

//16920 Expansion game

using namespace std;

char chess[1001][1001];
long long S[10];
int result[10];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

queue<pair<int,int>> Q[10];
queue<long long> sQ[10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N,M,P;
    string s;
    long long expanum;
    int turn;
    queue<pair<int,int>> tempQ;
    queue<long long> tempsQ;
    
    cin>>N>>M>>P;

    for(int i = 1;i<=P;++i)
    {
        cin>>S[i];
        result[i] = 0;
    }

    for(int i = 0;i<N;++i)
    {
        cin>>s;
        for(int j = 0;j<M;++j)
        {
            chess[i][j] = s[j];
            if(chess[i][j] == '#' || chess[i][j] == '.')
            {
                continue;
            }
            else
            {
                Q[int(chess[i][j] - '0')].push({i,j});
                sQ[int(chess[i][j] - '0')].push(0);
            }
        }
    }

    turn = 1;

    while(true)
    {
        bool flag = false;
        expanum = S[turn];

        for(int i = 1;i<=P;++i)
        {
            if(!Q[i].empty())
            {
                flag = true;
            }
        }

        if(flag == false)
        {
            break;
        }

        while(!Q[turn].empty())
        {
            pair<int,int> cur = Q[turn].front();
            int curexp = sQ[turn].front();
            Q[turn].pop();
            sQ[turn].pop();
            
            if(curexp >= expanum)
            {
                tempQ.push(cur);
                tempsQ.push(0);
                continue;
            }

            for(int dir = 0; dir<4; ++dir)
            {
                int x = cur.first + dx[dir];
                int y = cur.second + dy[dir];

                if(x < 0 || x >= N || y < 0 || y >= M)
                {
                    continue;
                }
                if(chess[x][y] == '.')
                {
                    chess[x][y] = char(turn+'0');
                    Q[turn].push({x,y});
                    sQ[turn].push(curexp+1);
                }
            }
        }

        while(!tempQ.empty())
        {
            Q[turn].push(tempQ.front());
            sQ[turn].push(tempsQ.front());
            tempQ.pop();
            tempsQ.pop();
        }

        ++turn;
        if(turn > P)
        {
            turn = 1;
        }
    }

    for(int i = 0;i<N;++i)
    {
        for(int j = 0;j<M;++j)
        {
            //cout<<chess[i][j];
            if(chess[i][j] == '#' || chess[i][j] == '.')
            {
                continue;
            }
            else
            {
                result[int(chess[i][j]-'0')]++;
            }
        }
        //cout<<'\n';
    }
    
    for(int i = 1;i<=P;++i)
    {
        cout<<result[i]<<" ";
    }
    
    return 0;
}