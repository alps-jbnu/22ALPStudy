#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cctype>
using namespace std;

long long arr[100000];

int main()
{
	int n;
	long long s;

	cin >> n >> s;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	long long st = 0;
	long long en = 0;
	
	long long min = 2100000000;
	
	long long tot = arr[0]; //รัวี

	while (en < n)
	{
		if (tot < s)
		{
			en++;
			tot = tot + arr[en];
		}
		else if( tot >= s)
		{
			if (min > en - st + 1)
			{
				min = en - st + 1;
			}
			tot = tot - arr[st];
			st++;
		}
	}

	if(min != 2100000000)
	cout << min;
	else
	{
		cout << 0;
	}
}