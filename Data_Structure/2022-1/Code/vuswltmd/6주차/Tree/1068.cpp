#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <queue>
#include <tuple>
using namespace std;

vector<int> node[55];
int size1[55];

int n;
int d;
int root;

int dfs(int cur, int par)
{
	size1[cur] = 1;
	for (auto nxt : node[cur])
	{
		if (par == nxt) continue;
		if (nxt == d) continue;
		size1[cur] += dfs(nxt, cur);
	}

	return size1[cur];
}

int main()
{	
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int par;
		cin >> par;

		if (par != -1)
		{
			node[par].push_back(i);
		}

		else if (par == -1)
		{
			root = i;
		}
	}

	cin >> d;
	if (d == root)
	{
		cout << 0 << '\n';
		return 0;
	}

	dfs(root, -1);

	int sum = 0;

	for (int i = 0; i < 50; i++)
	{
		if (size1[i] == 1)
		{
			sum = sum + size1[i];
		}
	}

	cout << sum;

}