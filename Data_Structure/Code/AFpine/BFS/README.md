# **Problem Solving Review**

## [벽 부수고 이동하기 3](https://www.acmicpc.net/problem/16933)

BFS를 이용하여 상황에 맞게 특정 위치에 도달하는 문제

### **문제점**

[BFS 내에서, 조건에 부합하는 다음(현재 위치 포함) 경로의 dist 값을 미리 변경하였다]

현재 상태가 밤일 때, 벽을 만나고 이어서 벽이 아닌 경우를 만나면 문제가 생긴다. 이 경우 벽이 아닌 다음 위치의 dist 값을 현재 dist 값에 1을 더하여 변경 하는데, 그 전에 벽을 만났을 때 밤이기 때문에 벽을 뚫지 못하고 현재 dist 값을 1 올려놓은 상태가 되어있다. 그 상황에서 벽이 아닌 곳의 dist를 1 올리기 때문에 총 dist가 2가 올라가는 상황이 발생한다.

### **문제 발생 이유**

이 전의 BFS 문제들에서 경로까지 도달하는 데 dist를 구하는 문제가 있었는데, BFS queue에서 현재 자신의 dist를 변경하는 조건의 문제가 없어서 dist 값을 미리 변경하여도 문제가 되지 않았다.

### **해결 방안**

다음 경로(현재 위치 포함)의 dist(혹은 다른 변수) 변경값 혹은 값 그 자체를 queue에 넣어서 BFS queue와 같이 작동 시킨다. 즉, queue에서 어떠한 값(보통 정점)을 push나 pop 할 때 어떠한 변수를 queue로 같이 관리하면 문제가 없다.

```cpp
 while(!q.empty())
    {
        pair<int,int> now = q.front();
        q.pop();
        int nowwall = wallq.front();
        wallq.pop();
        bool nowday = daynight.front();
        daynight.pop();
        int nowdist = distq.front();
        distq.pop();
        
        dist[nowwall][now.first][now.second] = nowdist;
        //distance initialization

        for(int dir = 0;dir<4;++dir)
        {
            int x = now.first + dx[dir];
            int y = now.second + dy[dir];
            
            if(x < 1 || x > N || y < 1 || y > M)
            {
                continue;
            }
            if(MAP[x][y] == '0' && visited[nowwall][x][y] == false)
            {//if (x,y) isn't wall
                visited[nowwall][x][y] = true;
                distq.push(dist[nowwall][now.first][now.second] + 1);
                q.push({x,y});
                wallq.push(nowwall);
                if(nowday == true)
                {//day and night change
                    daynight.push(false);
                }
                else
                {
                    daynight.push(true);
                }
            }
            else if(nowwall < K && MAP[x][y] == '1' && visited[nowwall+1][x][y] == false)
            {//if (x,y) is wall and current status can break wall
                if(nowday == true)
                {
                    visited[nowwall+1][x][y] = true;
                    distq.push(dist[nowwall][now.first][now.second] + 1);
                    q.push({x,y});
                    wallq.push(nowwall+1);
                    daynight.push(false);
                }
                else
                {//if current is night, can't break wall and distance is increase
                    distq.push(dist[nowwall][now.first][now.second] + 1);
                    q.push(now);
                    wallq.push(nowwall);
                    daynight.push(true);
                }
            }
        }
    }
```