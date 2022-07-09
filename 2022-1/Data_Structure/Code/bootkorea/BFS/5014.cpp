#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
const int MAX = 1000000 + 1;

int F, S, G, U, D;

int arr[MAX];

int BFS()
{
	queue<int> q;
	q.push(S);
	arr[S] = 1;

	while (!q.empty())
	{
		int f = q.front();
		q.pop();

		if (f == G)
		{
			return arr[f] - 1;
		}

		int next[2] = { (f + U), (f - D) };

		for (int i = 0; i < 2; i++)
		{
			if (1 <= next[i] && next[i] <= F && arr[next[i]] == 0)
			{	
				arr[next[i]] = arr[f] + 1;
				q.push(next[i]);
			}
		}
	}
	return -1;
}

int main() {
	cin >> F >> S >> G >> U >> D;

	int	result = BFS();

	if (result == -1)
	{
		cout << "use the stairs" << "\n";
	}
	else
	{
		cout << arr[G] - 1 << "\n";
	}
	
	return 0;
}	