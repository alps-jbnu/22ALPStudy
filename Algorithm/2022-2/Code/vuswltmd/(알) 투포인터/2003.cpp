#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int arr[10000];

int main()
{
	int n;
	cin >> n;

	int m;
	cin >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	int st = 0;
	int en = 0;
	int now = 0;
	int count = 0;

	while (en < n)
	{
		if (now + arr[en] < m)
		{
			now = now + arr[en];
			en++;
		}
		else if (now + arr[en] == m)
		{
			count++;
			now = now + arr[en];
			en++;
		}
		else if (now + arr[en] > m)
		{
			now = now - arr[st];
			st++;
		}
	}

	cout << count;
}