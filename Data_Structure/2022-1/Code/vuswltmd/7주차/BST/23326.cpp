#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
set<int> hong;

int main()
{
	int now = 1;
	int n;
	int q;
	cin >> n >> q;

	for (int i = 1; i <= n; i++)
	{
		int num; cin >> num;
		if(num)
		hong.insert(i);
	}

	for (int i = 0; i < q; i++)
	{
		int curr;
		cin >> curr;

		if (curr == 1)
		{
			int num;
			cin >> num;
			if (hong.find(num) != hong.end())
			{
				hong.erase(num);
			}
			else
			{
				hong.insert(num);
			}

		}
		else if (curr == 2)
		{
			int x;
			cin >> x;
			now = now + x;
			if (now > n)
			{	
				if (now % n == 0)
				{
					now = n;
				}
				else
				{
					now = now % n;
				}
			}

			cout << "now: " << now << '\n';
		}
		else if (curr == 3)
		{
			if (hong.empty()) cout << -1 << '\n';	
			else
			{
				auto it = hong.lower_bound(now);

				if (it != hong.end())
					cout << *it - now << '\n';
				else
					cout << n -now + *hong.begin() << '\n';
			}
			
		}
	}
}