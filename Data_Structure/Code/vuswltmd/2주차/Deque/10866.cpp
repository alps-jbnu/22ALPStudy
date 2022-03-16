#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iterator>
#include <list>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	deque<int> dq;

	while (n--)
	{
		string menu;
		cin >> menu;

		if (menu == "push_front")
		{
			int num;
			cin >> num;
			dq.push_front(num);
		}
		else if (menu == "push_back")
		{
			int num;
			cin >> num;
			dq.push_back(num);
		}
		else if (menu == "pop_front")
		{
			if (dq.empty())
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (menu == "pop_back")
		{
			if (dq.empty())
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (menu == "size")
		{
			cout << dq.size() << "\n";
		}
		else if (menu == "empty")
		{
			
			cout << dq.empty() << "\n";
			
		}
		else if (menu == "front")
		{
			if (dq.empty())
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << dq.front() << "\n";
			}
		}
		else if( menu == "back")
		{
			if (dq.empty())
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << dq.back() << "\n";
			}
		}
	}
}