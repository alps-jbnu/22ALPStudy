#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	int e;
	string st;
	stack<int> sk;

	cin >> N;
	for (int i = 0; i != N; ++i)
	{
		cin >> st;
		if (st == "push")
		{
			cin >> e;
			sk.push(e);
		}
		else if (st=="pop")
		{
			if (sk.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << sk.top() << "\n";
				sk.pop();
			}
		}
		else if (st=="size")
		{
			cout << sk.size() << "\n";
		}
		else if (st=="empty")
		{
			if (sk.empty())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else
		{
			if (sk.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << sk.top() << "\n";
			}
		}
	}

}