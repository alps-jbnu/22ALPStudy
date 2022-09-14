#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <deque>
using namespace std;

int arr[1005];
int d[1005];
int pre[1005];

int n;


int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		d[i] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (arr[i] > arr[j] && d[i] < d[j] + 1)
			{
				d[i] = d[j] + 1;
				pre[i] = j;
			}
		}
	}

	int maxi = 1;
	int maxd = d[1];

	for (int i = 2; i <= n; i++)
	{
		if (d[i] > maxd)
		{
			maxd = d[i];
			maxi = i;
		}
	}

	int cur = maxi;
	deque<int> dq;

	while (true)
	{
		dq.push_front(arr[cur]);
		if (cur == 1) break;
		cur = pre[cur];
	}

	cout << dq.size() << '\n';

	for (auto e : dq)
	{
		cout << e << ' ';
	}
}