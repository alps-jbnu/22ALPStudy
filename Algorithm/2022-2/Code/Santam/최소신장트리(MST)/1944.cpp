#include <bits/stdc++.h>
#define x first
#define y second
#define tp tuple<int,int,int>

using namespace std;

priority_queue<tp, vector<tp>, greater<tp>> pq; // x: 비용, y: u, z: v
char board[51][51]{};
int vis[51][51]{};
int d_x[4]{ 0,0,-1,1 };
int d_y[4]{ -1,1,0,0 };
int n, m, t, u, v;


int MST()
{
	int res = 0, find_k = 0; // 신장트리에 확정된 간선 수
	while (find_k < m&&!pq.empty()) //pq비어있는 경우 에러or시도 0 --> bfs방식
	{
		int cost, s, e;
		tie(cost, s, e) = pq.top(); pq.pop(); //pq에서 나오는 것은 가장 주행수가 적은 로봇
		if (board[s][e]=='1'||vis[s][e]<cost) continue;
		if (board[s][e] == 'K'&& vis[s][e]>10000 ) find_k++, res += cost-1,cost=1; //k점에서 새로운 출발을 위해 cost=0 ==> 로봇 복제조건
		vis[s][e] = cost; // 해당 지점에서 가장 최소의 값들만 저장 (pq의 메모리 초과 방지)
		for (int dir = 0; dir < 4; dir++)
		{
			pq.push({ cost + 1,s + d_x[dir],e + d_y[dir] });
		} //pq에 추가될 nxt는 현재 지점의 4방향이된다.
	}
	if (find_k == m) return res;
	return -1;
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	memset(vis, 10000, sizeof(int) * 51 * 51);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char c; cin >> c;
			board[i + 1][j + 1] = c;
			if (c == 'S') pq.push({ 1,i+1,j+1 }); // vis유무를 위한 cost=1로 시작
		}
	}
	cout << MST() << "\n";
	return 0;
}