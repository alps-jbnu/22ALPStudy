#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N,d;
vector<int> adj[55];
bool vis[55];
int bfs(int del)
{
	int num=0;
	queue<int> q;
	q.push(0);
	vis[0] = true;
	while (!q.empty())
	{
		int cur = q.front();  q.pop();
		if (cur == del)
			continue;
		for (auto nxt : adj[cur])
		{
			if (vis[nxt])	continue;
			vis[cur] = true;
			q.push(nxt);
		}
		if (adj[cur].size() == 0)	num++;
	}


	return num;
}

int main(void)
{
	cin >> N;
	int p;
	for (int i = 0; i < N; i++) {
		cin >> p;
		if (p != -1)
			adj[p].push_back(i);
	}
	cin >> d;
	
	cout << bfs(d);
	return 0;
}