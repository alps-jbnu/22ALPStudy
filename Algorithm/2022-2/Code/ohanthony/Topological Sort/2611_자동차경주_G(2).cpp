#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long
#define X first
#define Y second

int N, M, p, q, r;
/*
- N: 지점의 개수
- M: 도로의 개수
- p, q: p->q 지점으로 갈 수 있는 도로
- r: p->q에 부여된 점수
*/

vector<int> result[1005];
vector<pair<int, int>> road[1005];
int deg[1005];
int max_road[1005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	while(M--){
		cin >> p >> q >> r;
		road[p].push_back({q, r});
		deg[q]++;
	}

	queue<int> q;
	q.push(1); // 시작점이 주어짐
	result[1].push_back(1);
	while(!q.empty()){
		int cur = q.front();
		q.pop();

		for(int i = 0; i < road[cur].size(); i++){
			int nxt = road[cur][i].X;
			int num = road[cur][i].Y;

			// 각각의 점에서 최댓값 갱신
			if(max_road[nxt] < max_road[cur] + num){
				max_road[nxt] = max_road[cur] + num;
				result[nxt] = result[cur];
				result[nxt].push_back(nxt);
			}

			deg[nxt]--;
			if(deg[nxt] == 0) q.push(nxt);
		}
	}

	cout << max_road[1] << '\n';
	for(int i = 0; i < result[1].size(); i++){
		cout << result[1][i] << ' ';
	}
	return 0;
}
