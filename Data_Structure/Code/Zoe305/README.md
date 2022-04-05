## [유기농배추](https://www.acmicpc.net/problem/1012)

BFS를 이용해 탐색하고자 하는 배추가 이미 탐색한 구역의 배추인지 확인해서 총 배추 구역의 개수를 세는 문제

**문제점**

변수 cur의 자료형을 int라고 했을 때 에러 발생

```c++

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
}
```


**해결 방법**

문제 풀 때는 auto를 이용해 해결했지만, 스터디를 통해 cur의 자료형은 pair임을 알게 됨
