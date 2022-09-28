#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <queue>
#include <tuple>
#include <set>
#include <queue>
using namespace std;

int d[10005];
int coin[25];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;

	while (T--)
	{
		for (int i = 0; i <= 10000; i++)
		{
			d[i] = 0;
			if (i <= 25)
			{
				coin[i] = 0;
			}
		}


		int N;
		cin >> N;

		for (int i = 1; i <= N; i++)
		{
			cin >> coin[i];
		}

		int M;
		cin >> M;

		d[0] = 1;

		for (int i = 1; i <= N; i++)
		{
			for (int j = coin[i]; j <= M; j++)
			{
				d[j] = d[j] + d[j - coin[i]];
			}
		}

		cout << d[M] <<'\n';
	}

}