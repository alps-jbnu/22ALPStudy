#include<iostream>
#include<set>

using namespace std;
int num[1000000];
set<int> lank[102];

int main(void)
{
	int N;
	cin >> N;
	while (N--)
	{
		int P, L;
		cin >> P >> L;
		lank[L].insert(P);
		num[P] = L;
	}
	int M;
	cin >> M;
	while (M--)
	{
		string s;
		cin >> s;
		if (s == "add")
		{
			int P, L;
			cin >> P >> L;
			lank[L].insert(P);
			num[P] = L;
		}
		else if (s == "recommend")
		{
			int n;
			cin >> n;
			if (n == 1)
			{
				for (int i = 100; i >= 0; i--)
				{
					if (lank[i].empty())	continue;
					cout << *prev(lank[i].end()) << "\n";
					break;
				}
			}
			if (n == -1)
			{
				for (int i = 0; i <= 100; i++)
				{
					if (lank[i].empty())	continue;
					cout << *(lank[i].begin()) << "\n";
					break;
				}
			}
		}
		else if (s == "solved")
		{
			int p;
			cin >> p;
			lank[num[p]].erase(p);
		}
	}

	return 0;
}