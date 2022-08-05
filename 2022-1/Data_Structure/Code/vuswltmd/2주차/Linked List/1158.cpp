#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iterator>
#include <list>
#include <deque>
#include <stack>
#include <utility>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int k;
	cin >> k;

	list<int> L;
	list<int>::iterator cursor;
	vector<int> kk;

	for (int i = 1; i <= n; i++)
	{
		L.push_back(i);
	}

	cursor = L.begin();

	while (1)
	{
		if (L.size() == 1)
		{
			break;
		}
		else
		{
			for (int i = 1; i < k; i++)
			{
				cursor++;
				if (cursor == L.end())
				{
					cursor = L.begin();
				}
			}

			kk.push_back(*cursor);
			cursor = L.erase(cursor);
			if (cursor == L.end())
			{
				cursor = L.begin();
			}
		}
	}

	for (auto a : L)
	{
		kk.push_back(a);
	}

	cout << "<";

	for (int i = 0; i < kk.size(); i++)
	{
		cout << kk[i];

		if (i != kk.size() - 1)
		{
			cout << ", ";
		}
		else
		{
			cout << ">";
		}
	}

}
