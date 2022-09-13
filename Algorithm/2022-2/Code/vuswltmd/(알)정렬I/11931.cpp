#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <cctype>
using namespace std;

long long card[100005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long mxval = -(1ll << 62) -1;
	int cnt = 0;
	int mxcnt = 0;

	int n;
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		cin >> card[i];
	}

	sort(card, card + n);

	for (int i = 0; i < n; i++)
	{
		if (i == 0 || card[i-1] != card[i])
		{	
			cnt = 1;
			if (cnt > mxcnt)
			{
				mxcnt = cnt;
				mxval = card[i];
			}
		}
		else if(card[i] == card[i-1])
		{
			cnt++;
			if (cnt > mxcnt)
			{
				mxcnt = cnt;
				mxval = card[i];
			}
		}
	}

	cout << mxval;
}