#include <bits/stdc++.h>

using namespace std;

vector<int> p(2500,-1);
int find_parent(int x)
{
    if(p[x] < 0) return x;
    return p[x] = find_parent(p[x]);
}
bool is_diff_group(int a, int b)
{
    a = find_parent(a); b = find_parent(b);
    if(a == b) return false;
    if(a > b) p[a] = b;
    else p[b] = a;
    return true;
}

int N, M;
char maze[50][50];
int maze_K[50][50];
int dist[50][50];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<tuple<int,int,int>> tp;

void bfs(pair<int,int> p)
{
    for(int i = 0; i < N; i++)
    {
        fill(dist[i],dist[i]+N,0);
    }
    dist[p.first][p.second] = 1;
    queue<pair<int,int>> q;
    q.push(p);
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(maze[nx][ny] == '1') continue;
            if(dist[nx][ny]) continue;
            if(maze[nx][ny] == 'K')
                tp.push_back(make_tuple(dist[cur.first][cur.second], maze_K[p.first][p.second], maze_K[nx][ny]));
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push(make_pair(nx,ny));
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    vector<pair<int,int>> v;
    int k = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> maze[i][j];
            if(maze[i][j] == 'S' || maze[i][j] == 'K')
            {
                v.push_back(make_pair(i,j));
                maze_K[i][j] = k++;
            }
        }
    }
    for(int i = 0; i < v.size(); i++)
    {
        bfs(v[i]);
    }
    sort(tp.begin(), tp.end());
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < tp.size(); i++)
    {
        int a,b,c; tie(c,a,b) = tp[i];
        if(!is_diff_group(a,b)) continue;
        ans += c;
        cnt++;
        if(cnt == M) break;
    }
    if(cnt == M)
        cout << ans;
    else
        cout << -1;
    return 0;
}
