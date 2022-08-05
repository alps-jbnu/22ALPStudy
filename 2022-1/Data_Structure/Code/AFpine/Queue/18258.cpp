#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
	int num;
	deque<int> d{};
	queue<int>q{};
	string s;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> s;
		if (s == "push")
		{
			cin >> num;
			q.push(num);
		}
		else if (s == "pop")
		{
			if (q.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (s == "size")
		{
			cout << q.size() << "\n";
		}
		else if (s == "empty")
		{
			cout << int(q.empty()) << "\n";
		}
		else if (s == "front")
		{
			if (q.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << q.front() << "\n";
			}
		}
		else if (s == "back")
		{
			if (q.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << q.back() << "\n";
			}
		}
	}
}