#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int DONE = 1, YET = 0, IGNORE = -1;
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

int yetCnt;
int N, M, A[1001][1001];
bool visited[1001][1001];

int bfs(){
    queue<P> q;     // 토마토의 위치를 담을 Queue
    int count = 0; // 며칠이 걸렸는지 확인용

    // 이미 익은 토마토들을 push
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(A[i][j] == DONE){
                visited[i][j] = true;
                q.push({i, j});
            }
        }
    }

    // 토마토가 다 익지 않고, q가 차있으면
    // q가 비어있는 상태 -> 아예 불가능한 상태로 해석 가능
    // 모든 토마토가 다 익었다면 q에 1개 이상의 원소 존재
    while(yetCnt > 0 && !q.empty()){
        int qsize = q.size();
        while(qsize--){
            P curr = q.front();
            q.pop();

            int x = curr.first, y = curr.second;

            for(int k=0; k<4; k++){
                int nx = x + dx[k], ny = y + dy[k];
                if(!(0 <= nx && nx < N && 0 <= ny && ny < M)) continue; // 배열 범위 확인
                if(visited[nx][ny]) continue; // 이미 방문했으면 pass
                if(A[nx][ny] == IGNORE) continue; // -1 공간은 은 무시
                
                visited[nx][ny] = true;
                q.push({nx, ny});
                yetCnt--;
            }
        }
        count++;
    }

    // 만약 모든 토마토가 익지 않았으면 -1를 return
    int result = (yetCnt == 0? count : -1);

    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> A[i][j];
            if(A[i][j] == YET) yetCnt++;
        }
    }

    // 이미 모든 토마토가 익었다면 0, 아니라면 익히기 시도
    if(yetCnt == 0) cout << 0;
    else cout << bfs();

    return 0;
}