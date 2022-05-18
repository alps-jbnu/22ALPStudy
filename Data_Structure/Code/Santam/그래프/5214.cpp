#include <iostream>
#include <queue>

using namespace std;

vector<int> board[101001];
int vis[101001] = { 0 };

int main()
{
	queue<int> q;
	int n, m, k;
	cin >> n >> k >> m;
	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < k;j++)
		{
			int temp;
			cin >> temp;
			board[temp].push_back(n + 1 + i);
			board[n + 1 + i].push_back(temp);
		}
	}
	vis[1] = 1;
	q.push(1);
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int i = 0;i < board[cur].size();i++)
		{
			if (vis[board[cur][i]] != 0) continue;
			vis[board[cur][i]] = vis[cur] + 1;
			q.push(board[cur][i]);
		}
	}

	if (vis[n] != 0) cout << vis[n]/2+1;
	else cout << -1;

	return 0;
}

/*
입력되는 하이퍼 튜브 내의 역들을 간선으로 연결하려 했지만 시간초과가 날거 같아서 하이퍼 튜브 자체를 역으로 둔다고 생각했다.
1. 하이퍼 튜브도 역으로 취급한다는 가정하에 역의 개수는 101000개가 될 수 있고, 입력을 받을 때, 하이퍼 역과 기존 역을 연결 시켜준다.
2. bfs를 1번 역을 시작점으로 해준 최단 거리 구하는 방식으로 진행
3. 결과값을 뽑아 낼때, 하이퍼 역을 갔다가 다시 본래 역으로 나오는 과정에서 불필요한 거리 1추가되므로 결과값을 2로 나눠준다
==> 하이퍼 역은 원래 역이아니 통로이므로 통로를 이용할때마다 하나의 간선이 둘로 쪼개진다.
4. 나눈 값에 출발역도 방문한 역이므로 1더해줘서 출력

*/