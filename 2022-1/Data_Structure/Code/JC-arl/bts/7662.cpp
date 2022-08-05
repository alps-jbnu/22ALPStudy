#include<iostream>
#include<set>
//#include<>
using namespace std;
int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int k;
		cin >> k;
		multiset<int> ms;
		while (k--)
		{
			char ch;
			cin >> ch;
			if (ch == 'D')//delete
			{
				int n;
				cin >> n;
				if (ms.empty())	continue;
				if (n == 1)	ms.erase(prev(ms.end()));
				else ms.erase(ms.begin());
			}
			else //add
			{
				int n;
				cin >> n;
				ms.insert(n);
			}
		}
		if (ms.empty())	cout << "EMPTY\n";
		else cout << *prev(ms.end()) << " " << *ms.begin()<<"\n";
	}

	return 0;
}