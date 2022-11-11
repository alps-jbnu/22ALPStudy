#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>

#define INF 987654321;
#define RED 1
#define BLUE 2
using namespace std;

// 1707 - 이분 그래프
int v, e;
vector<vector<int>> graph;
vector<int> isVisited;

void input(){
    cin >> v >> e;
    graph.assign(v + 1, vector<int>(0, 0));
    isVisited.assign(v + 1, false);

    for(int i = 0; i < e; i++){
        int s, e;
        cin >> s >> e;
        graph[s].emplace_back(e);
        graph[e].emplace_back(s);
    }
}

void DFS(int cur){
	// 아직 방문하지 않은 정점이라면 빨간색으로 칠한다.
    if(!isVisited[cur]) isVisited[cur] = RED;

	// 현재 정점과 연결된 정점들을 모두 방문
    for(int i = 0; i < graph[cur].size(); i++){
        int next = graph[cur][i];

		// 아직 방문하지 않은 정점이라면 현재 정점과 반대되는 색으로 칠한다.
        if(!isVisited[next]){
            if(isVisited[cur] == RED)   isVisited[next] = BLUE;
            else if(isVisited[cur] == BLUE) isVisited[next] = RED;
            DFS(next);
        }
    }
}

// 이분 그래프인지 확인하는 함수
bool isBipartite(){
	// 모든 정점들을 돌아보면서 인접한 정점과의 색이 같은지 확인
    for(int cur = 1; cur <= v; cur++){
        for(int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur][i];
            // 만일 인접한 정점과 색이 같다면 이분 그래프가 아님
            if(isVisited[cur] == isVisited[next])   return false;
        }
    }
    return true;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testcase;
    cin >> testcase;
    while(testcase--){
        input();
        // 그래프가 모두 연결되어 있다는 보장이 없으니, 방문 처리가 되지 않은 정점들에 DFS 실행
        for(int i = 1; i <= v; i++){
            if(!isVisited[i])   DFS(i);
        }
        
        if(isBipartite())   cout << "YES\n";
        else    cout << "NO\n";
    }

    return 0;
}