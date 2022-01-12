#include <iostream>
#include <queue>

using namespace std;

const int MAX = 200002;
int N, K;
bool visited[MAX];

// 범위, 방문 여부 확인
bool isPossible(int next){
    return (0 <= next && next < MAX && !visited[next]);
}

int bfs(){
    queue<int> q;
    int count = 0; //찾는데 얼마나 걸렸는지?
    bool isArrived = false;

    // 수빈이의 시작 위치 초기화
    visited[N] = true;
    q.push(N);

    while(!isArrived && !q.empty()){
        int qsize = q.size();
        while(qsize--){
            int curr = q.front();
            q.pop();

            // 동생 위치에 도달했는지?
            if(curr == K){
                return count;
            }

            // 가능한 3가지 경우 탐색
            int lst[3] = {curr - 1, curr + 1, curr * 2};
            for(int next : lst){
                if(!isPossible(next)) continue;

                visited[next] = true;
                q.push(next);
            }

        }
        count++;
    }
    
    return count;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    cout << bfs();

    return 0;
}