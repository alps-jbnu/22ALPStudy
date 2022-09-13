#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <deque>
using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	int l;
	cin >> n >> l;

	deque<pair<int, int>> DQ;

	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;

		while (!DQ.empty() && DQ.back().second >= num)
		{
			DQ.pop_back();
		}

		DQ.push_back({i, num});

		if (DQ.front().first <= i - l)
		{
			DQ.pop_front();
		}

		cout << DQ.front().second << ' ';

		//cout << DQ.front().second;
	}
}