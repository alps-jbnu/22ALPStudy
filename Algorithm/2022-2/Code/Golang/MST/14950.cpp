#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <vector>
#include <queue>

#define endl "\n"

using namespace std;

int N, M, t; //N=도시의 개수(노드), M=도로의 개수(간선), t=정복할때마다 드는 누적비용
vector<pair<int, pair<int, int>>>edges;	//cost , {도시a, 도시b}
int parent[10001];

int findParent(int x) {
	if (x == parent[x]) return x;
	else return x = findParent(parent[x]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//입력
	cin >> N >> M >> t;
	//Union-Find 기본 세팅
	//부모 테이블에서, 부모자신을 자기자신으로 초기화
	for (int i = 1; i <= N; i++) {    
		parent[i] = i;
	}
	//간선 입력
	for (int i = 0; i < M; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		//비용을 기준으로 정렬하기 위해 튜플의 첫번째 원소에 비용 삽입    
		edges.push_back({ cost,{a,b} });    
	}
	//정렬
	sort(edges.begin(), edges.end());

	int ans = 0, cnt = 0;;
	for (int i = 0; i < edges.size(); i++) {
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		if (findParent(a) != findParent(b)) {
			unionParent(a, b);
			ans += cost + cnt * t;
			cnt++;
		}
	}
	cout << ans;
}
/*
문제 : 
1. N개의 도시(1번부터 N번)와 M개의 도로
1-1. 모든 도시에는 그 도시를 연결하는 양방향 도로가 있음
1-2. 1번 도시에서 시작
2. 특정 도시 B를 정복하고 싶다면, B와 도로로 연결된 도시들 중에서 적어도 하나를 정복하고 있어야 한다.
3. 한 번 도시가 정복되면, 모든 도시는 경계를 하게 되기 때문에 모든 도로의 비용이 t만큼 증가

입력 :
1. 도시의 개수 N, 도로의 개수 M, 정복 시마다 증가하는 도로의 비용 t
	(N<=10000, M<=30000, t<10)
2. M개의 줄동안 도시A, 도시B, 도로의 비용C
	(A != B, C<= 10000)

출력 : 
1. 모든 도시를 정복하는데 사용되는 최소 비용

풀이 : MST

*/