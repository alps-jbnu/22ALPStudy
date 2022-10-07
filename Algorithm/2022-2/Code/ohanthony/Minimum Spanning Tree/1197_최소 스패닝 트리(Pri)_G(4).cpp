#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long
#define X first
#define Y second

int v, e;
/*
- V: 정점의 개수
- E: 간선의 개수
- A, B: 정점 정보
- C: A->B 가중치
*/

// {비용, 정점 번호}
vector<pair<int, int>> adj[10005];

// chk[i]: i번째 정점이 최소 신장 트리에 속해있는가?
bool chk[10005];


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> v >> e;
	for(int i = 0; i < e; i++){
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({c, b});
		adj[b].push_back({c, a});
	}

	chk[1] = true;

	int count = 0; //  현재까지 선택된 간선의 수
	int sum = 0;

	// {비용, 정점 1, 정점 2}
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;
	 
	for(auto nxt : adj[1]) pq.push({nxt.X, 1, nxt.Y});

	while(count < v-1){
		int cost, a, b;
		tie(cost, a, b) = pq.top();
		pq.pop();

		if(chk[b]) continue;

		sum += cost;
		chk[b] = 1;
		count++;
		for(auto nxt : adj[b]){
			if(!chk[nxt.Y]){
				pq.push({nxt.X, b, nxt.Y});
			}
		}
	}

	cout << sum;
	return 0;
}
 