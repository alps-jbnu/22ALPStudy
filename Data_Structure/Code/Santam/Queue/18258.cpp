#include <iostream>
#include <queue>

using namespace std;

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	queue<int> q;
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		string temp;
		cin >> temp;
		if (temp == "push")
		{
			int push_int;
			cin >> push_int;
			q.push(push_int);
		}
		if (temp == "pop")
		{
			if (q.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << q.front() << "\n";
				q.pop();
			}
		}
		if (temp == "size")
		{
			cout << q.size() << "\n";
		}
		if (temp == "empty")
		{
			cout << q.empty() << "\n";
		}
		if (temp == "front")
		{
			if (q.empty()) cout << -1 << "\n";
			else cout << q.front() << "\n";
		}
		if (temp == "back")
		{
			if (q.empty()) cout << -1 << "\n";
			else cout << q.back() << "\n";
		}

	}
	return 0;
}

/*
1.바로 이전문제와 같다고 볼 수 있기에 10845 큐 참조
*/