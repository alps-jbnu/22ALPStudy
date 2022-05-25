#include <iostream>
#include <set>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		multiset<int> ms;
		int k;
		cin >> k;

		for (int i = 0; i < k; i++)
		{
			char iord; cin >> iord;
			int n; cin >> n;

			if (iord == 'I')
			{
				ms.insert(n);
			}
			else
			{
				if (n == 1)
				{
					if (ms.empty()) continue;
					else ms.erase(prev(ms.end()));
				}
				else
				{
					if (ms.empty()) continue;
					else ms.erase(ms.begin());
				}
			}
		}

		if (ms.empty())
			cout << "EMPTY" << "\n";
		else
		{
			cout << *prev(ms.end());
			cout << " ";
			cout << *ms.begin();
			cout << '\n';
		}
	}

	
}