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
	string n;
	cin >> n;

	list<char> L;

	for (char a : n)
	{
		L.push_back(a);
	}

	int m;
	cin >> m;

	list<char>::iterator cursor = L.end();


	for (int i = 0; i < m; i++)
	{

		char op;
		cin >> op;

		if (op == 'P')
		{
			char add_alpa;
			cin >> add_alpa;

			L.insert(cursor, add_alpa);
		}

		else if (op == 'L')
		{
			if (cursor == L.begin())
			{
				cursor = L.begin();
			}
			else
				cursor--;
		}

		else if (op == 'D')
		{
			if (cursor == L.end())
			{
				cursor = L.end();
			}
			else
				cursor++;
		}

		else if (op == 'B')
		{
			if (cursor == L.begin())
			{
				cursor = L.begin();
			}
			else
			{
				cursor--;
				cursor = L.erase(cursor);
			}

		}
	}

	for (char c : L)
	{
		cout << c;
	}
}