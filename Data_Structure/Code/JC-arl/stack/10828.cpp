#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(void)
{
	string s;
	stack<int> st;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		int x;
		if (s == "push")
		{
			cin >> x;
			st.push(x);
		}
		else if (s == "pop")
		{
			if (st.empty())
				cout << -1 << "\n";
			else
			{
				cout << st.top() << "\n";
				st.pop();
			}
		}
		else if (s == "size")
		{
			cout << st.size() << "\n";
		}
		else if (s == "empty")
		{
			if (st.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (s == "top")
		{
			if (st.empty())
				cout << -1 << "\n";
			else
			{
				cout << st.top() << "\n";
			}
		}



	}


	return 0;
}