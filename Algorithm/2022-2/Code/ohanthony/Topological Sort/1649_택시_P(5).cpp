#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int N, M, A, B, K, C;
/*
- N: 교차로 개수
- M: 도로의 개수
- A: 시작점
- B: 끝점
- K: 방문해야할 중간 지점의 개수
- C: 방문해야 할 중간지점
*/

vector<int> adj[1005];
int deg[1005];

set<int> temp; // 방문해야 하는 중간지점
int result[1005]; // 현재까지 찾은 경로의 개수를 저장하는 배열
int vis[1005]; // 해당 교차로까지 주어진 중간지점 중 방문한 교차로의 수

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	cin >> N >> M;
	while(M--){
		int st, en;
		cin >> st >> en;
		adj[st].push_back(en); // 방향 그래프이기 때문에 다음과 같은 처리
		deg[en]++; // st->en으로 가는 것이므로 en의 indegree값 +1;
	}

	// 시작점과 끝점 그리고 반드시 거쳐가야 하는 중간지점을 고려해 위상정렬로 접근하는 것이 핵심
	cin >> A >> B >> K;
	while(K--) {
		cin >> C;
		temp.insert(C);
	}

	queue<int> q;
	result[A]++; // 시작점에서 시작한 경로는 +1

	for(int i = 1; i <= N; i++){
		if(deg[i] == 0) q.push(i);
	}
	
	while(!q.empty()){
		int cur = q.front(); // cur: 현재
		q.pop();

		// 중간지점이 들어있는지 확인, 한번 방문한 중간지점은 일방통행이라는 조건으로(방향성) 다시 방문하지 않음
		if(temp.find(cur) != temp.end()) vis[cur]++;

		for(auto nxt : adj[cur]){ // nxt: 다음
			// 다음 교차로까지의 중간지점 방문 숫자와 현재 교차로까지의 중간지점 방문 숫자가 같을 경우
			if(vis[nxt] == vis[cur]) result[nxt] += result[cur];
			else if(vis[nxt] < vis[cur]){ // 다음 교차로까지의 중간지점 방문 숫자보다 현재 교차로까지의 중간지점 방문 숫자가 많을 경우
				vis[nxt] = vis[cur];
				result[nxt] = result[cur];
			}

			deg[nxt]--;
			if(deg[nxt] == 0) q.push(nxt);
		}
	}

	if(vis[B] == temp.size()) cout << result[B];
	else cout << 0;

	return 0;
}
