#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cctype>
using namespace std;
vector<int> xi;
vector<int> xi2;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		xi.push_back(num);
		xi2.push_back(num);
	}

	sort(xi2.begin(), xi2.end());
	xi2.erase(unique(xi2.begin(), xi2.end()), xi2.end());

	for (int i = 0; i < n; i++)
	{
		cout << lower_bound(xi2.begin(), xi2.end(), xi[i])
			- xi2.begin() << ' ';
	}
	
}