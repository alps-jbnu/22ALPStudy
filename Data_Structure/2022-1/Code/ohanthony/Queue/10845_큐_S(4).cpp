#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	queue<int> q;

	for (int i = 0; i < n; i++)
	{
		string order;
		cin >> order;

		if (order == "push")
		{
			int num;
			cin >> num;
			q.push(num);
		}
		else if (order == "pop")
		{
			if (!q.empty())
			{
				cout << q.front() << "\n";
				q.pop();
			}
			else cout << -1 << "\n";
		}
		else if (order == "size")
		{
			cout << q.size() << "\n";
		}
		else if (order == "empty")
		{
			if (!q.empty())
			{
				cout << 0 << "\n";
			}
			else cout << 1 << "\n";
		}
		else if (order == "front")
		{
			if (!q.empty())
			{
				cout << q.front() << "\n";
			}
			else cout << -1 << "\n";
		}
		else if (order == "back")
		{
			if (!q.empty())
			{
				cout << q.back() << "\n";
			}
			else cout << -1 << "\n";
		}
	}

	return 0;
}