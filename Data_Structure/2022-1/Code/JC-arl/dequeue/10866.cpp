#include<iostream>
#include<deque>
#include<string>
using namespace std;

int main(void)
{
	int N;
	cin >> N;
	cin.ignore();
	deque<int> dq;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		if (s == "push_back")
		{
			int x;
			cin >> x;
			dq.push_back(x);
		}
		else if (s == "push_front")
		{
			int x;
			cin >> x;
			dq.push_front(x);
		}
		else if (s == "pop_front")
		{
			if (dq.empty())
				cout << -1 << endl;
			else
			{
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}
		else if (s == "pop_back")
		{
			if (dq.empty())
				cout << -1 << endl;
			else
			{
				cout << dq.back() << endl;
				dq.pop_back();
			}
		}
		else if (s == "size")
		{
			cout << dq.size() << endl;
		}
		else if (s == "empty")
		{
			if (dq.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (s == "front")
		{
			if (dq.empty())
				cout << -1 << endl;
			else
				cout << dq.front() << endl;
		}
		else if (s == "back")
		{
			if (dq.empty())
				cout << -1 << endl;
			else
				cout << dq.back() << endl;
		}
	}




	return 0;
}