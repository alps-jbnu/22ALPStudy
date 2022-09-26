#include <bits/stdc++.h>
const int MAX = 32000 + 1;
using namespace std;

int N, M;
int vertex[MAX];
vector<int> vec[MAX];

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		vertex[b]++;
		vec[a].push_back(b); // 위상정렬 그래프 생성
	}

	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (vertex[i] == 0) q.push(i);
	}

	while (!q.empty())
	{
		while (!q.empty())
		{
			int num = q.front();
			q.pop();
			cout << num << " ";

			for (int next : vec[num])
			{
				vertex[next]--;
				if (!vertex[next]) q.push(next);
			}
		}
	}
	return 0;
}