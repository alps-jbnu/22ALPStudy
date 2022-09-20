#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	stack<int> s;

	for (int i = 0; i < n; i++)
	{
		string order;
		cin >> order;
		if (order == "push")
		{
			int num;
			cin >> num;
			s.push(num);
		}
		else if (order == "pop")
		{
			if (!s.empty())
			{
				cout << s.top() << "\n";
				s.pop();
			}
			else cout << "-1" << "\n";
			
		}
		else if (order == "size")
		{
			cout << s.size() << "\n";
		}
		else if (order == "empty")
		{
			if (!s.empty()) cout << "0" << "\n";
			else cout << "1" << "\n";
		}
		else
		{
			if (!s.empty()) cout << s.top() << "\n";
			else cout << "-1" << "\n";
		}
	}

	return 0;
}