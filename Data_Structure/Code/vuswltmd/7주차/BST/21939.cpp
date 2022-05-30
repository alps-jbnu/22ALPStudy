#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
set<int> problevel[102];
int probnum[100002];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int p;
		int l;
		cin >> p >> l;
		probnum[p] = l;
		problevel[l].insert(p);
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		string command;
		cin >> command;

		if (command == "recommend")
		{
			int num;
			cin >> num;
			
			if (num == 1)
			{
				for (int i = 100; i >= 0; i--)
				{
					if (problevel[i].empty()) continue;
						cout << *(prev(problevel[i].end())) << '\n';
						break;
				}
			}
			else if(num == -1)
			{
				for (int i = 0; i <= 100; i++)
				{
					if(problevel[i].empty()) continue;
						cout << *problevel[i].begin() << '\n';
						break;
				}
			}

		}
		else if (command == "add")
		{
			int p;
			int l;
			cin >> p >> l;
			probnum[p] = l;
			problevel[l].insert(p);
		}
		else
		{
			int p;
			cin >> p;
			problevel[probnum[p]].erase(p);
		}
	}
}