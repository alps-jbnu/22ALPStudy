#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cctype>
using namespace std;

vector<int> pl[100];
vector<int> pl2[100];
vector<int> pl3[100];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	cin >> m >> n;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int num;
			cin >> num;
			pl[i].push_back(num);
			pl2[i].push_back(num);
		}
		sort(pl2[i].begin(), pl2[i].end());
		pl2[i].erase(unique(pl2[i].begin(), pl2[i].end()), pl2[i].end());
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{	
			int order = lower_bound(pl2[i].begin(), pl2[i].end(), pl[i][j]) - pl2[i].begin();
			pl3[i].push_back(order);
		}
	}
	int count = 0;

	for (int i = 0; i < m-1; i++)
	{
		for (int j = i+1; j < m; j++)
		{
			if (pl3[i] == pl3[j])
			{
				count++;
			}
		}
	}

	cout << count;

}