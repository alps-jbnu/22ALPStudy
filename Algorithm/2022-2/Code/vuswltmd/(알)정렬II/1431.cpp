#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <cctype>
using namespace std;

bool cmp(string a, string b)
{
	if (a.length() < b.length())
	{
		return true;
	}
	else if (a.length() > b.length())
	{
		return false;
	}
	else 
	{
		int a_sum = 0;
		int b_sum = 0;
		
		for (int i = 0; i < a.length(); i++)
		{
			if (isdigit(a[i]))
			{
				a_sum = a_sum + (int)a[i];
			}
		}

		for (int i = 0; i < b.length(); i++)
		{
			if (isdigit(b[i]))
			{
				b_sum = b_sum + (int)b[i];
			}
		}

		if (a_sum > b_sum)
		{
			return false;
		}
		else if(a_sum < b_sum)
		{
			return true;
		}
		else
		{
			if (a > b)
			{
				return false;
			}
			else if(a == b)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string gui[50];

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> gui[i];
	}

	sort(gui, gui + n, cmp);

	for (int i = 0; i < n; i++)
	{
		cout << gui[i] << '\n';
	}
}