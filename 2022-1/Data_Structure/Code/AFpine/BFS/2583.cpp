#include <bits/stdc++.h>

using namespace std;

int mono[100][100];
bool visited[100][100];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int BFS(int M, int N, int i, int j)
{
    int area = 1;
    queue<pair<int,int>> q;
    q.push({i,j});
    visited[i][j] = true;
    while(!q.empty())
    {
        pair<int,int> now = q.front();
        q.pop();
        for(int dir = 0;dir<4;++dir)
        {
            int nx = now.first + dx[dir];
            int ny = now.second + dy[dir];

            if(nx < 0 || nx >= M || ny < 0 || ny >= N)
            {
                continue;
            }
            if(mono[nx][ny] == 0 && visited[nx][ny] == false)
            {
                ++area;
                visited[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
    return area;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    priority_queue<int,vector<int>,greater<int>> pq;

    int N,M,K;
    int x1,x2,y1,y2;

    cin>>M>>N>>K;

    for(int i = 0;i<K;++i)
    {
        cin>>x1>>y1>>x2>>y2;
        
        for(int j = y1; j< y2; ++j)
        {
            for(int k = x1; k < x2; ++k)
            {
                mono[j][k] = 1;
            }
        }
    }

    for(int i = 0;i<M;++i)
    {
        for(int j = 0;j<N;++j)
        {
            if(mono[i][j] == 0 && visited[i][j] == false)
            {
                int temp = BFS(M,N,i,j);
                pq.push(temp);
            }
        }
    }

    cout<<pq.size()<<'\n';
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }

    return 0;
}