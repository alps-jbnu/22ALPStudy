#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 100000 + 1;

int N, R, Q;
int result;
int Visited[MAX];
int arr[MAX];
vector<int> vec[MAX];

int DFS(int x)
{
	if (arr[x] != 0) return arr[x]; // already finished

	Visited[x] = 1;
	int result = 1;

	for (int i = 0; i < vec[x].size(); i++)
	{
		int next = vec[x][i];

		if (!Visited[next]) result += DFS(next);
		else continue;
	}
	arr[x] = result;
	return arr[x];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> R >> Q;

	for (int i = 0; i < N - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	arr[R] = DFS(R);

	for (int i = 0; i < Q; i++)
	{
		int u;
		cin >> u;
		cout << arr[u] << "\n";
	}

	return 0;
}