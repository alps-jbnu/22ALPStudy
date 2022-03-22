#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

int M;
char temp, c;
string s;
stack<char> L, R;

int main()
{
	cin >> s;
	for (int i = 0; i < (int)s.size(); i++)
	{
		L.push(s[i]);
	}
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> temp;

		if (temp == 'L')
		{
			if (!L.empty())
			{
				R.push(L.top());
				L.pop();
			}
		}
		else if (temp == 'D')
		{
			if (!R.empty())
			{
				L.push(R.top());
				R.pop();
			}
		}
		else if (temp == 'B')
		{
			if (!L.empty())
			{
				L.pop();
			}
		}
		else if (temp == 'P')
		{
			cin >> c;
			L.push(c);
		}
	}

	while (!L.empty())
	{
		R.push(L.top());
		L.pop();
	}
	while (!R.empty())
	{
		cout << R.top();
		R.pop();
	}

	return 0;
}