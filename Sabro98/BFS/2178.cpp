#include <iostream>
#include <queue>
#define WALL 0

using namespace std;

typedef pair<int, int> P;

const int MAX = 101;
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

int N, M, A[MAX][MAX];
bool visited[MAX][MAX];

// 경계, 방문 여부, 벽 여부 확인
bool isPossible(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < M && !visited[x][y] && A[x][y] != WALL);
}

int bfs(){
    int count = 0; // 몇 턴이 걸렸는지?
    bool isArrived = false;
    queue<P> q;

    // 시작 위치 초기화
    visited[0][0] = true;
    q.push({0, 0});

    while(!isArrived && !q.empty()){
        int qsize = q.size();
        while(qsize--){
            P curr = q.front();
            q.pop();

            int x = curr.first, y = curr.second;

            // 목표 지점에 도착했다면 체크 해주고 break
            if(x == N - 1 && y == M - 1) {
                isArrived = true;
                break;
            }

            for(int k=0; k<4; k++){
                int nx = x + dx[k], ny = y + dy[k];

                // 다음 공간의 가능성 확인 후 불가능하면 pass
                if(!isPossible(nx, ny)) continue;
                
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }

        count++;
    }

    // 도착하지 못했다면 -1을 return
    int result = (isArrived? count : -1);
    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    
    char c;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> c;
            A[i][j] = c - '0';
        }
    }

    cout << bfs();

    return 0;
}