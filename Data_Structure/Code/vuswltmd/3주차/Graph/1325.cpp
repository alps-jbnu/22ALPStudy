#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

vector<int> V[10005];
int V_K[10005]; //각 컴퓨터의 최대거리를 저장할 배열
int vis[10005];
int n;               
int m;                


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;


	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		V[y].push_back(x); // 예) 4와 5가 3에 연결됨
	}

	int mmxx = 0; //전체의 최대거리

	for (int i = 1; i <= n; i++)
	{

		for (int j = 1; j <= n; j++)
		{
			vis[j] = -1;
		}

		int num = 0; //해킹한 컴퓨터 수
		queue<int> Q;
		Q.push(i);
		vis[i] = 0;

		while (!Q.empty())
		{
			int cur = Q.front(); Q.pop();

			for (auto nxt : V[cur])
			{
				if (vis[nxt] == -1)
				{
					vis[nxt] = vis[cur] + 1; // 거리로 풀 필요는 없음
					num++;
					Q.push(nxt);
				}
			}
		}

		mmxx = max(mmxx, num);

		V_K[i]=num;
	}

	for (int j = 1; j <= n; j++)
	{
		if (V_K[j] == mmxx)
		{
			cout << j << " ";
		}
	}
}