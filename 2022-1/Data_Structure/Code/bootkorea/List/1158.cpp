#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K;
queue<int> q;

int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}

	int temp;
	cout << "<";
	while (q.size())
	{
		if (q.size() == 1)
		{
			cout << q.front() << ">";
			q.pop();
			break;
		}

		for (int i = 1; i < K; i++)
		{
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ", ";
		q.pop();
	}

	return 0;
}