#include<iostream>
#include<deque>
#include<string>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;

	deque<int> ptr;
	string s;
	int x;

	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		if (s == "push_front")
		{
			cin >> x;
			ptr.push_front(x);
		}
		else if (s == "push_back")
		{
			cin >> x;
			ptr.push_back(x);
		}
		else if (s == "pop_front")
		{
			if (!ptr.empty())
			{
				cout << ptr.front() << "\n";
				ptr.pop_front();
			}
			else cout << -1 << "\n";
		}
		else if (s == "pop_back")
		{
			if (!ptr.empty())
			{
				cout << ptr.back() << "\n";
				ptr.pop_back();
			}
			else cout << -1 << "\n";
		}
		else if (s == "size")
		{
			cout << ptr.size() << "\n";
		}
		else if (s == "empty")
		{
			cout << ptr.empty() << "\n";
		}
		else if (s == "front")
		{
			if (!ptr.empty())
				cout << ptr.front() << "\n";
			else cout << -1 << "\n";
		}
		else
		{
			if (!ptr.empty())
				cout << ptr.back() << "\n";
			else cout << -1 << "\n";
		}
	}

	return 0;
}