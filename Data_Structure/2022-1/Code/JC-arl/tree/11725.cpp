#include<iostream>
#include<vector>
#include<stack>

using namespace std;
vector<int> adj[100001];
int p[100001];
int N;

void dfs(int cur)
{
	for (int nxt : adj[cur])
	{
		if (p[cur] == nxt)	continue;
		p[nxt] = cur;
		dfs(nxt);
	}
}
int main(void)
{

	int u, v;
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	for (int i = 2; i <= N; i++)	cout << p[i] << "\n";
	return 0;
}