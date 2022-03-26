#include <bits/stdc++.h>

using namespace std;

static const int INF = 100000000;

char building [31][31][31];
bool visited [31][31][31]; 
int dist [31][31][31];
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


    int L,R,C;
    string s;

    while(true)
    {
        tuple<int,int,int> start,escape;
        queue<tuple<int,int,int>> q;

        cin>>L>>R>>C;

        if(L == 0 && R == 0 && C == 0)
        {
            break;
        }
        for(int l = 1;l<=L;++l)
        {
            for(int r = 1;r<=R;++r)
            {
                cin>>s;
                for(int c = 1;c<=C;++c)
                {
                    visited[l][r][c] = false;
                    dist[l][r][c] = INF;
                    building[l][r][c] = s[c-1];
                    if(s[c-1] == 'S')
                    {
                        start = {l,r,c};
                        visited[l][r][c] = true;
                        dist[l][r][c] = 0;
                    }
                    if(s[c-1] == 'E')
                    {
                        escape = {l,r,c};
                        dist[l][r][c] = INF;
                    }
                }
            }
        }
        
        q.push(start);
        while(!q.empty())
        {
            tuple<int,int,int> now = q.front();
            q.pop();

            for(int dir = 0;dir<6;++dir)
            {
                int z = get<0>(now) + dz[dir];
                int x = get<1>(now) + dx[dir];
                int y = get<2>(now) + dy[dir];

                if(x < 1 || x > R || y < 1 || y > C || z < 1 || z > L)
                {
                    continue;
                }
                if(building[z][x][y] != '#' && visited[z][x][y] == false)
                {
                    visited[z][x][y] = true;
                    dist[z][x][y] = dist[get<0>(now)][get<1>(now)][get<2>(now)] + 1;
                    q.push({z,x,y});
                }
            }
        }

        if(dist[get<0>(escape)][get<1>(escape)][get<2>(escape)] == INF)
        {
            cout<<"Trapped!\n";
        }
        else
        {
            cout<<"Escaped in "<< dist[get<0>(escape)][get<1>(escape)][get<2>(escape)] << " minute(s).\n";
        }
    }
    
    return 0;
}