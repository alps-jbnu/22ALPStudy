#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
int dist[20001]; //최단 거리를 저장할 배열 선언
const int INF = 2147483647; //int의 최댓값 
vector<pair<int, int> > graph[20001]; //정점 번호, 가중치를 저장할 벡터 선언 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int V, E, K;
	cin >> V >> E >> K;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(w, v)); //입력을 벡터에 추가하기 
	}
	fill(dist, dist + V + 1, INF); //dist 배열 초기화하기 
 
	dist[K] = 0; //시작점 0으로 바꾸기 
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; 
    //가중치를 기준으로 정렬, min heap
	pq.push(make_pair(dist[K], K)); //시작점 추가하기 
	while (!pq.empty()) {
		pair<int, int> cur = pq.top(); 
		pq.pop();
		int dist = cur.first;
		int idx = cur.second;
		if (dist[idx] != dist) //가중치가 작은 간선을 dist에 넣고, idx에 정점 저장하기 
			continue; //dist[idx]와 dist가 다르면, 더 짧은 경로를 찾은 것 ..
		for (int i = 0; i < graph[idx].size(); i++) {
			pair<int, int> next = graph[idx][i];
			int cost = next.first; //정점과 연결된 간선을 돌면서, cost에 가중치, nidx에 다음 정점
			int nidx = next.second;
			if (dist[nidx] > dist + cost) { //현재 저장되어 있는 거리보다 작으면은
				dist[nidx] = dist + cost; // 갱신해주기 
				pq.push(make_pair(dist[nidx], nidx));
			}
		}
	}
	for (int i = 1; i <= V; i++) { 
		if (dist[i] == INF) //경로가 존재하지 않을 경우 
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
 
	return 0;
}