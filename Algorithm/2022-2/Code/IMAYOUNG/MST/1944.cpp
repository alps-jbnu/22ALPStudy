#include <bits/stdc++.h>
using namespace std;
//1944 - 로봇 복제 
const int MAX_N=51;
const int MAX_M=252;
const int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
typedef pair<int,int> P;

int N, M, pos, root[MAX_M];
char board[MAX_N][MAX_N];
int adj[MAX_M][MAX_M];
P node[MAX_M];
map<P,int> m;
bool visited[MAX_N][MAX_N];

vector<pair<int,pair<int,int> > > edge;

// Union-find Algorithm for MST
int find(int x) {
  if (!root[x]) return x;
  return root[x] = find(root[x]);
}

int merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return false;
  root[b] = a;
  return true;
}

// 현재 노드(here)에서 다른 노드 간에 거리를 측정하여 edge 생성
void bfs(int here) {
  memset(visited, 0, sizeof(visited));
  int sx = node[here].first;
  int sy = node[here].second;
  queue<P> q;
  q.push(P(sx, sy));
  visited[sx][sy] = true;

  int depth = 0;
  while (!q.empty()) {
    int qSize = q.size();
    while (qSize--) {
      int cur_x = q.front().first;
      int cur_y = q.front().second;
      q.pop();
      if (m[P(cur_x, cur_y)]) {
        adj[here][m[P(cur_x, cur_y)]] = depth;
      }
      for (int d=0; d<4; d++) {
        int nx = cur_x + dir[d][0];
        int ny = cur_y + dir[d][1];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if (visited[nx][ny]) continue;
        if (board[nx][ny] == '1') continue;
        visited[nx][ny] = true;
        q.push(P(nx,ny));
      }
    }
    depth++;
  }

}

// 모든 노드가 연결되어 있는지 확인
int dfs(int x, int y) {
  int ret = 0;
  visited[x][y]=true;
  if (m[P(x,y)]) ret++;
  for (int d=0; d<4; d++) {
    int nx = x + dir[d][0];
    int ny = y + dir[d][1];
    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
    if (visited[nx][ny]) continue;
    if (board[nx][ny] == '1') continue;
    ret += dfs(nx, ny);
  }
  return ret;
}

int main() {
  scanf("%d%d",&N, &M);
  M++; // 열쇠(M) + 시작(S) = M+1

  // 노드를 번호 매김하고 Map에 저장한다.
  for (int i=0; i<N; i++) {
    scanf("%s", board[i]);
    for (int j=0; j<N; j++) {
      if (board[i][j] == 'S' || board[i][j] == 'K') {
        node[++pos] = P(i,j);
        m[P(i,j)] = pos;
      }
    }
  }

  // 모든 노드가 연결되어 있는지 확인한다.
  if (dfs(node[1].first, node[1].second) != M) return !printf("-1\n");

  // BFS를 이용하여 그래프의 edge를 생성한다.
  for (int i=1; i<=M; i++) {
    bfs(i);
    for (int j=1; j<=M; j++)
      edge.push_back(make_pair(adj[i][j], make_pair(i,j)));
  }

  // MST 알고리즘을 위한 edge sort
  sort(edge.begin(), edge.end());

  // MST 알고리즘
  int ret = 0;
  for (int i=0; i<edge.size(); i++) {
    // merge 가능한 경우 MST 그래프의 edge 추가
    if (merge(edge[i].second.first, edge[i].second.second))  {
      ret += edge[i].first;
    }
  }

  printf("%d\n", ret);
  return 0;
}