#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int N, M, A, B;
/*
- N: 학생 수
- M: 키를 비교한 횟수
- A, B: 키를 비교한 두 학생의 번호, 학생 A가 학생 B 앞에 서야 한다.
*/

vector<int> adj[32005];
int deg[32005];

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	cin >> N >> M;
	while(M--){
		cin >> A >> B;
		adj[A].push_back(B); // 방향 그래프이기 때문에 다음과 같은 처리
		deg[B]++; // A->B로 가는 것이므로 B의 indegree값 +1 증가
	}

	queue<int> q;
	for(int i = 1; i <= N; i++){
		if(deg[i] == 0) q.push(i); // indegree 값이 0인 정점들을 큐에 넣음
	}

	while(!q.empty()){ // 큐가 빌 때까지 반복
		int cur = q.front();
		q.pop();
		cout << cur << ' ';
		for(auto nxt : adj[cur]){
			deg[nxt]--; // 해당 정점으로부터 연결된 모든 정점의 indegree 값을 1 감소 시킴
			if(deg[nxt] == 0) q.push(nxt); // 마찬가지로 indegree 값이 0이면 그 정점을 큐에 추가
		}
	}
	return 0;
}
