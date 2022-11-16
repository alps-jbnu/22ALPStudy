#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cstring>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int N, M, A, B, K;

vector<int> graph[1001];	//int 타입의 단방향 그래프
int indegree[1001];

set<int> mustVisit;		//필수 방문 지점 저장 (set : 중복X, 자동 정렬)  *반드시 set이어야하는 건 아님.

int visit[1001];		//해당 지점에서의 필수 방문 지점 방문 횟수
int route[1001];		//DP : 각 지점별 경로 개수

int mustVisit_arr[1001];	//필수 방문 지점 -1로 저장
/*
입력 :
1. 교차로의 개수 N 도로의 개수 M
	(1 ≤ N ≤ 1000)
2. M개에 줄에는 도로의 정보를 알려주는 시작점과 끝점
3. 시작점 A 끝점 B 방문해야할 중간 지점의 개수 K
4. 방문해야할 중간 지점 C1, C2, …, Ck
*/
void input() {
	cin >> N >> M;
	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		indegree[v]++;
	}

	cin >> A >> B >> K;
	for (int i = 0; i < K; i++) {
		cin >> u;
		mustVisit.insert(u);
		mustVisit_arr[u] = -1;
	}
}

/*
해당 노드에 방문해야하는지 확인 위함
*/
bool isInmustVisit(int node) {
	if (mustVisit.find(node) != mustVisit.end()) return true;
	else return false;
}

void Topology() {
	queue<int> que;
	//처음 경로 개수 1 <- 
	route[A] = 1;
	//간선이 0 인 정점 모두 추가 <-
	for (int i = 1; i <= N; i++) {
		if (!indegree[i]) que.push(i);
	}

	while (!que.empty()) {
		int now = que.front();
		que.pop();

		// Cn 노드 방문
		if (isInmustVisit(now)) visit[now]++;


		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];

			//해당 노드(next)가 필수 
			// ->	Σ(이전의 노드(now)의 경로 개수)
			if (visit[next] == visit[now]) {
				route[next] += route[now];
			}
			//해당 노드가 필수 x
			// ->	가장 마지막 필수 노드의 것 그대로 저장
			else if (visit[next] < visit[now]) {	//처음에 visit[next]는 0일 테니깐...
				visit[next] = visit[now];
				route[next] = route[now];
			}
			if (--indegree[next] == 0) que.push(next);
		}
	}
}
/*
출력 :
1. 조건을 만족하는 경로의 개수 S (S < 2,000,000,000)
1-1. 경로가 존재하지 않을 경우엔 0을 출력
*/
int main() {
	fastio
		input();
	Topology();

	if (visit[B] == mustVisit.size()) cout << route[B];
	else cout << 0;

	return 0;
}

/*
문제 :
1. 1부터 N번까지 숫자로 붙여진 N개의 교차로
2. 어떠한 교차로 사이에도 하나의 도로로 이루어짐
-> 간선 1개
3. 어떤 교차로에서 출발해서 다시 그 교차로로 돌아올 수 없음
-> 순환X
4. 중간 교차로들의 방문 순서는 상관 없음
5. 조건을 만족하는 경로의 개수 출력
-> DP 사용해야겠구나...

입력 :
1. 교차로의 개수 N 도로의 개수 M
	(1 ≤ N ≤ 1000)
2. M개에 줄에는 도로의 정보를 알려주는 시작점과 끝점
3. 시작점 A 끝점 B 방문해야할 중간 지점의 개수 K
4. 방문해야할 중간 지점 C1, C2, …, Ck

출력 :
1. 조건을 만족하는 경로의 개수 S (S < 2,000,000,000)
1-1. 경로가 존재하지 않을 경우엔 0을 출력

풀이 : 위상정렬 + DP (경로 개수)
*?	*?	*10	*30	*60	*100
*?	 ?	*10	*20	*30	*40
*1	*4	*10	*10	*10	*10
*1	*3	*6	 ?	 ?	*?
*1	*2	*3	 ?	 ?	*?
*1	*1	*1	*?	*?	*?

*/