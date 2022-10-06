#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long
#define X first
#define Y second

int n, m, t, a, b, c;
/*
- n: 도시의 개수
- m: 도로의 개수
- t: 정복할 때마다 증가하는 도로의 비용
- a, b: 도시 a, b
- c: 필요 비용
*/

vector<pair<int, int>> road[10005];
bool vis[10005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> t;
	while(m--){
		cin >> a >> b >> c;
		road[a].push_back({c, b});
		road[b].push_back({c, a});
	}

	// {비용, 정점1, 정점2}
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;

	vis[1] = true; // 문제조건
	for(auto nxt : road[1]) pq.push({nxt.X, 1, nxt.Y});
	
	int cnt = 0; // 현재 선택된 간선의 수
	int result = 0;

	while(cnt < n-1){
		int cost, a, b;
		tie(cost, a, b) = pq.top();
		pq.pop();

		if(vis[b]) continue;

		vis[b] = true;
		result += cost + cnt*t;
		cnt++;
		
		for(auto nxt : road[b]){
			if(!vis[nxt.Y]) pq.push({nxt.X, b, nxt.Y});
		}
	}
	
	cout << result;
	return 0;
}
 