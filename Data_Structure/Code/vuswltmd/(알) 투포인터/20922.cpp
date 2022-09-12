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

int arr[200000];
int vis[200000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int k;
	cin >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	
	int en = 0;
	vis[arr[en]] = 1;
	int max = 0;
	
	for (int st = 0; st < n; st++)
	{
		while (en < n - 1 && vis[arr[en+1]] < k)
		{
			en++;
			vis[arr[en]]++;
		}

		if (max < en - st + 1)
		{
			max = en - st + 1;
		}

		vis[arr[st]]--;
	}

	cout << max;

}