#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iterator>
#include <list>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string a;
		cin >> a;

		list<char> L;
		list<char>::iterator cursor;

		cursor = L.begin();


		for (auto j : a)
		{
			if (j == '<')
			{
				if (cursor != L.begin())
				{
					cursor--;
				}

			}
			else if (j == '>')
			{
				if (cursor != L.end())
				{
					cursor++;
				}

			}
			else if (j == '-')
			{
				if (cursor != L.begin())
				{
					cursor--;
					cursor = L.erase(cursor);
				}

			}
			else
			{
				L.insert(cursor, j);
			}


		}

		for (auto h : L)
		{
			cout << h;
		}
		cout << "\n";


	}
}