#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define X first
#define Y second
int board[51][51];
int vis[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int M, N, K;
queue <pair<int, int>> Q;

int bfs(int x, int y){
    vis[x][y] = true;
    Q.push({x,y});
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(vis[nx][ny] || board[nx][ny] != 1) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}// 가독성을 높이기 위해 bfs 함수를 따로 만들어서 구현

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        cin >> M >> N >> K;
        int x, y;
        for(int i = 0; i < K; i++){
            cin >> x >> y;
            board[y][x] = 1;
        }//테스트 케이스만큼 배추밭 받기

        int worm = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++){
                if(board[i][j] == 1 && !vis[i][j]){
                    bfs(i, j); // 가독성을 높이기 위해 bfs 부분 따로 구현
                    worm++;
                }
            }//지렁이의 개수 구하기

        cout << worm << "\n";
        for(int i = 0; i < N; i++){
            fill(board[i], board[i]+M, 0);
            fill(vis[i], vis[i]+M, false);//하나의 테스트 케이스가 끝나면 다음 테스트를 위해 초기화
        }
    }
    return 0;
}

/*18번째 줄에 왜 int cur이라고 하면 에러가 난다 -> auto cur을 쓰기
 예제 2번을 넣었을 때 답이 1이 나온다 왜지? -> 41번째 줄에 board[y][x]로 쓰기 */