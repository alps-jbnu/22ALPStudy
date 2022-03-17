#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iterator>
#include <list>
#include <deque>
#include <utility>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l;
	deque<pair<int, int>> dq;

	cin >> n >> l;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		while (!dq.empty() && dq.back().second >= num)
		{
			dq.pop_back();
		}

		dq.push_back(make_pair(i, num));

		if (dq.front().first < i-l)
		{
			dq.pop_front();
		}

		cout << dq.front().second << " ";
	}
	
}