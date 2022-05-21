#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int MAX = 50 + 1;

int N, R, del;
vector<int> parent[MAX];

int DFS(int cur)
{
	int result = 1;
	int child = 0;

	for (auto ch : parent[cur])
	{
		if (ch == del) continue;
		child += DFS(ch);
	}
	if (child) return child;
	else return result;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		if (x == -1) R = i;
		else parent[x].push_back(i);
	}

	cin >> del;

	if (R != del) cout << DFS(R);
	else cout << 0;

	return 0;
}