#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iterator>
#include <list>
#include <queue>
using namespace std;

int main()
{
	int n;
	cin >> n;
	queue<int> q;

	while (n--)
	{
		string menu;
		cin >> menu;

		if (menu == "push")
		{
			int num;
			cin >> num;

			q.push(num);
		}
		else if (menu == "pop")
		{
			if (q.empty() == true)
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << q.front() << "\n";
				q.pop();
			}
			
		}
		else if (menu == "size")
		{
			cout << q.size() << '\n';
		}
		else if (menu == "empty")
		{
			cout << q.empty()<< "\n";
		}
		else if (menu == "front")
		{
			if (q.empty())
			{
				cout << -1 << "\n";
			}
			else
			cout << q.front() << "\n";
		}
		else if (menu == "back")
		{
			if (q.empty())
			{
				cout << -1 << "\n";
			}
			else
				cout << q.back() << "\n";
		}
	}
}