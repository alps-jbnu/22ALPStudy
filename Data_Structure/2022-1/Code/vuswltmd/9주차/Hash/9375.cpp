#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
using namespace std;


int T;


int main(void) 
{
	cin >> T;

	while (T--)
	{
		unordered_map<string, int> mp;
		int n;
		cin >> n;

		if (n == 0)
		{
			cout << 0 << '\n';
			continue;
		}
		int sum = 1;

		for(int i = 0; i < n; i++)
		{
			string name;
			string kind;

			cin >> name >> kind;

			if (mp.find(kind) == mp.end())
			{
				mp[kind] = 1;
			}
			else
			{
				mp[kind]++;
			}
		}

		vector<pair<string, int>> V(mp.begin(), mp.end());

		for (int i = 0; i < V.size(); i++)
		{
			sum = sum * (V[i].second + 1);
		}

		cout << sum - 1 << endl;
	}
}