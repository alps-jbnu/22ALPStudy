#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <vector>
#include <queue>

#define endl "\n"

using namespace std;

tuple<int, int, int> edge[200000];
vector<int> p(300, -1);
//부모 루트 구하기
int find(int x) {
	if (p[x] < 0)return x;
	return p[x] = find(p[x]);
}
//작은 쪽이 부모
bool Union(int u, int v) {
	u = find(u);	//u의 루트 노드
	v = find(v);	//v의 루트 노드
	if (u == v)return false;	//같은 집합
	//다른 집합
	if (u > v) p[v] = u;
	else p[u] = v;
	return true;	//다른 집합
}

const int MapSize = 55;
bool visit[MapSize][MapSize];
char map[MapSize][MapSize];
int N;
vector<int> x;
vector<int> y;
int BFS(int startX, int startY, int endX, int endY) {
	for (int i = 0; i < MapSize; i++)
	{
		for (int j = 0; j < MapSize; j++)
		{
			visit[i][j] = false;
		}
	}
	queue<pair<int, int>> q;
	q.push({ startX, startY });
	visit[startX][startY] = true;
	int deep = 0;
	while (!q.empty()) {
		//깊이(Level) 구하기
		int sz = q.size();
		for (int z = 0; z < sz; z++) {
			pair<int, int> cur = q.front(); q.pop();
			if (cur.first == endX && cur.second == endY) return deep;
			int dx[4] = { 0,-1,0,1 };
			int dy[4] = { 1,0,-1,0 };
			for (int i = 0; i < 4; i++)
			{
				pair<int, int> next = { cur.first + dx[i], cur.second + dy[i] };
				if (next.first < 0 || next.first >= N ||
					next.second < 0 || next.second >= N) continue;
				if (map[next.first][next.second] !='1' && visit[next.first][next.second] == false) {
					q.push({ next.first, next.second });
					visit[next.first][next.second] = true;
				}
			}
		}
		deep++;
	}
	return deep;
}

int main() {
	ios::sync_with_stdio, cin.tie(0);
	int M;
	cin >> N >> M;	//열쇠의 개수 : M+1

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'S' || map[i][j] == 'K') {
				x.push_back(i);
				y.push_back(j);
			}

		}
	}

	int v = M + 1; //정점 개수
	int e = v * (v - 1) / 2;	//전체 간선 개수
	int idx = 0;	//edge
	for (int i = 0; i < x.size()-1; i++)
	{
		for (int j = i+1; j < x.size(); j++)
		{
			//BFS 과정에서 간선 넣기
			//한 정점에서 시작
			int startX = x.at(i);
			int startY = y.at(i);
			int endX = x.at(j);
			int endY = y.at(j);
			int cost = BFS(startX, startY, endX, endY);
			edge[idx++] = { cost, i, j };
			if (visit[startX][startY] == false || visit[endX][endY] == false) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	sort(edge, edge + e);
	int count = 0;
	int ans = 0;
	for (int i = 0; i < e; i++)
	{
		int a, b, cost;
		tie(cost, a, b) = edge[i];
		if (!Union(a, b)) continue;	//같은 집합이면 간선 추가x
		ans += cost;	//가중치 더하기
		count++;
		if (count == v - 1) break;	//MST는 간선 = 정점 - 1 이다.
	}
	if (count != v - 1) cout << -1 << endl;
	else cout << ans << endl;
	
	return 0;
}
/*
어려웠던 점 : 
1. 간선의 개수
1-1. 정점 v개일 떄 간선의 개수는 v*(v-1)/2 인 것을 틀림.
1-2. 잘못 계산하여 edge의 크기 떄문에 OutOfBounds 런타임 에러가 남.

문제 :
1. 로봇은 복제 장치를 이용하면 자기 자신을 똑같은 로봇으로 원하는 개수만큼 복제시킬 수 있다.
1-1. 열쇠가 있는 곳들과 로봇이 출발하는 위치에 로봇이 복제할 수 있는 장치를 장착
2. 로봇이 열쇠가 있는 위치에 도달했을 때 열쇠를 찾은 것
3. 하나의 칸에 동시에 여러 개의 로봇이 위치할 수 있으며, 로봇이 한 번 지나간 자리라도 다른 로봇 또는 자기 자신이 다시 지나갈 수 있다. 
4. 복제에는 시간이 들지 않으며, 로봇이 움직이는 횟수의 합은 분열된 로봇 각각이 움직인 횟수의 총 합을 말한다. 
5. 복제된 로봇이 열쇠를 모두 찾은 후 같은 위치로 모일 필요는 없다.

입력 :
1. 미로의 크기 N 열쇠의 개수 M
	(4 ≤ N ≤ 50) (1 ≤ M ≤ 250)
2. N째 줄동안 미로의 정보가 주어짐
2-1. 1 : 미로의 벽
2-2. 0 : 지나다닐 수 있는 길
2-3. S : 로봇이 출발하는 위치 (1개)
2-4. K : 열쇠의 위치 (M개)
2-5. S와 K에서만 복제 가능

출력 :
1. 모든 로봇이 움직인 횟수의 총 합
1-1. 모든 열쇠를 찾는 것이 불가능한 경우 -1을 출력

풀이 :
1. 전반적인 과정
1-1. 이 미로는 S와 K가 정점인 트리 구조라고 생각해보자.
1-2. 모든 로봇은 S와 K에서 복제할 수 있으니 모든 정점에서 다음 K를 찾을 수 있다.
1-3. 따라서 이 트리의 MST를 구하면 그것이 로봇이 이동한 최솟값이다.
1-4. S에서도 복제가 가능하니 MST의 시작점이 꼭 S일 필요는 없다.
2. BFS : 경로의 길이 구하기
2-1. 입력값 : 시작x,y좌표, 끝x, y좌표
2-2. 반복 : 간선의 총 개수만큼
2-3.출력 : 깊이 == 간선의 가중치 
2-3-1. 모든 열쇠를 찾는 것이 불가능한 경우 -1을 출력
3. MST 실행
*/