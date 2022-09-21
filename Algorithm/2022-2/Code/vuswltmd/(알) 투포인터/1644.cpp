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
int demi[4000000];
int demi2[4000000];
int demi2_count = 0;

int main()
{
	int n;
	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		demi[i] = i;
	}

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (demi[i] == 0) continue;

		for (int j = 2 * i; j <= n; j += i)
		{
			demi[j] = 0;
		}
	}

	for (int i = 0; i <= n; i++)
	{
		if (demi[i] != 0)
		{
			demi2[demi2_count] = demi[i];
			demi2_count++;
		}
	}

	int count = 0;
	int st = 0;
	int en = 0;
	int now = 0;

	while (en < demi2_count)
	{

		if (now + demi2[en] < n)
		{
			now = now + demi2[en];
			en++;
		}
		else if (now + demi2[en] == n)
		{
			count++;
			now = now + demi2[en];
			en++;
		}
		else if (now + demi2[en] > n)
		{
			now = now - demi2[st];
			st++;
		}
	}

	cout << count;
}