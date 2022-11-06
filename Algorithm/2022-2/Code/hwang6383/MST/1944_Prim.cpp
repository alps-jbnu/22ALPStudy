#include <bits/stdc++.h>

using namespace std;

int N, M;
bool check[251];
char maze[50][50];
int maze_SK[50][50];
int dist[50][50];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<pair<int,int>> vec[251];

void bfs(pair<int,int>& p)
{
    for(int i = 0; i < N;i++)
    {
        fill(dist[i], dist[i]+N,0);
    }
    dist[p.first][p.second] = 1;
    queue<pair<int,int>> q;
    q.push(p);
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        for(int i =0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(maze[nx][ny] == '1') continue;
            if(dist[nx][ny]) continue;
            if(maze[nx][ny] == 'K')
            {
                vec[maze_SK[nx][ny]].push_back(make_pair(dist[cur.first][cur.second], maze_SK[p.first][p.second]));
                vec[maze_SK[p.first][p.second]].push_back(make_pair(dist[cur.first][cur.second], maze_SK[nx][ny]));
            }
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push(make_pair(nx,ny));
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<tuple<int,int,int>,
                    vector<tuple<int,int,int>>,
                    greater<tuple<int,int,int>>> pq;
    
    cin >> N >> M;
    vector<pair<int,int>> v;
    int k = 1;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> maze[i][j];
            if(maze[i][j] == 'S' || maze[i][j] == 'K')
            {
                v.push_back(make_pair(i,j));
                maze_SK[i][j] = k++;
            }
        }
    }
    for(int i = 0; i < v.size(); i++)
    {
        bfs(v[i]);
    }
    check[1] = true;
    int ans = 0;
    int cnt = 0;
    for(auto nxt : vec[1])
        pq.push(make_tuple(nxt.first,1,nxt.second));
    while(cnt < M && !pq.empty())
    {
        int a, b, c; tie(c,a,b) = pq.top(); pq.pop();
        if(check[b]) continue;
        ans += c;
        cnt++;
        check[b] = true;
        for(auto nxt : vec[b])
        {
            if(!check[nxt.second])
                pq.push(make_tuple(nxt.first, b, nxt.second));
        }
    }
    if(cnt == M)
        cout << ans;
    else
        cout << -1;
    return 0;
}
