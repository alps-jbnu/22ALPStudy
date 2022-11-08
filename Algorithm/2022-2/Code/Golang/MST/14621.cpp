#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <vector>

#define endl "\n"
using namespace std;
tuple<int, int, int> edge[10011];
vector<int> p(1011, -1);
vector<char> University(1011);

bool check_WM(int a, int b) {
	if (University[a] != University[b]) return true;
	return false;
}
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
int main() {
	ios::sync_with_stdio, cin.tie(0);
	int v, e;	//정점, 간선
	cin >> v >> e;
	for (int i = 1; i <= v; i++)
	{
		char ch;
		cin >> University[i];
	}
	for (int i = 0; i < e; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		edge[i] = { cost, a, b };
	}
	sort(edge, edge + e);
	int count = 0;
	int ans = 0;
	for (int i = 0; i < e; i++)
	{
		int a, b, cost;
		tie(cost, a, b) = edge[i];
		//W와 M을 연결하는 도로인지 확인 : true -> Union Find
		if (check_WM(a, b)) {
			if (!Union(a, b)) continue;	//같은 집합이면 간선 추가x
			ans += cost;	//가중치 더하기
			count++;
			if (count == v - 1) break;	//MST는 간선 = 정점 - 1 이다.
		}
	}
	if (count != v - 1) cout << -1 << endl;
	else cout << ans << endl;
}
/*
메모리 초과 :
1. Union()에서 u와 v의 변수를 제활용하지 않고 P[]를 사용하였더니 메모리 초과가 나왔다. (스택 오버플로우)

문제 :
1. 사심 경로 - 남초 대학교와 여초 대학교들을 연결하는 도로로만 이루어짐
	-> 기존 MST에서 남초와 여초를 구분할 수 있어야 함.
2. 어떤 대학교에서든 모든 대학교로 이동이 가능한 경로
3. 경로의 길이는 최단 거리

입력 :
1. 학교의 수 N, 도로의 개수 M
	(2 ≤ N ≤ 1000) (1 ≤ M ≤ 10000)
2. 각 학교 나열 (남초 대학교M, 여초 대학교W)
3. M개의 줄에 학교u 학교v 거리d
	(1 ≤ u, v ≤ N) , (1 ≤ d ≤ 1000)

출력 :
1. 경로 길이
1-1. 모든 학교를 연결하는 경로가 없을 경우 -1 출력

풀이 :
1. check_WM : W와 M을 연결하는 도로인지 확인 : true -> Union Find
2. Union, Find : 다른 집합인지 확인 : true -> 경로 길이 더하기
3. MST 완료 -> 모든 대학이 연결되어 있는지 확인(Find로 루트 노드가 전부 같은지 확인) : true -> 경로 길이 출력, false -> -1 출력
*/