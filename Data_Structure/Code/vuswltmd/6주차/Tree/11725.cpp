#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
vector<int> node[100001];
int p[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n-1; i++)
	{
		int x, y;
		cin >> x >> y;

		node[x].push_back(y);
		node[y].push_back(x);
	}
	queue<int> q;
	q.push(1);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int nxt : node[cur])
		{
			if (p[cur] == nxt) continue;
			p[nxt] = cur;
			q.push(nxt);
		}
	}

	for (int i = 2; i <= n; i++)
	{
		cout << p[i] << '\n';
	}
}