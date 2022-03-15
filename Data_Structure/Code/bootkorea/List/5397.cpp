#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

int n;
string s;
stack<char> st1, temp;

int main()
{
	cin >> n;
	

	for (int i = 0; i < n; i++)
	{
		string result;
		cin >> s;

		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == '-')
			{
				if (!st1.empty()) st1.pop();
			}
			else if (s[j] == '<')
			{
				if (!st1.empty())
				{
					temp.push(st1.top());
					st1.pop();
				}
			}
			else if (s[j] == '>')
			{
				if (!temp.empty())
				{
					st1.push(temp.top());
					temp.pop();
				}
			}
			else
			{
				st1.push(s[j]);
			}
		}

		while (!temp.empty())
		{
			st1.push(temp.top());
			temp.pop();
		}

		while (!st1.empty())
		{
			result += st1.top();
			st1.pop();
		}
		reverse(result.begin(), result.end());
		
		cout << result << "\n";
	}
	return 0;
}