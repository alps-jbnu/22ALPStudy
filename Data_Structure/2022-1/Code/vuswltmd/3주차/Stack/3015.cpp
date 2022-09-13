#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <stack>
using namespace std;

long long ans = 0;
stack<pair<int, int>> S;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	while (n--)
	{
		int h;
		cin >> h;

		int cnt = 1;

		while (!S.empty() && S.top().first <= h)
		{
			ans = ans + S.top().second;
			
			if (h == S.top().first)
			{
				cnt = cnt + S.top().second;
			}

			S.pop();
		}

		if (!S.empty())
		{
			ans++;
		}

		S.push({ h, cnt });
	}

	cout << ans;
}