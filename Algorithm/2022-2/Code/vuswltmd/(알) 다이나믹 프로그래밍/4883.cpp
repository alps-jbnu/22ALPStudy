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

int board[100005][3];
int d[100005][3];
int test = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		int n;
		cin >> n;
		
		if (n == 0)
		{
			return 0;
		}

		test++;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				int num;
				cin >> num;

				board[i][j] = num;
			}
		}

		d[1][1] = board[1][1];
		d[1][2] = d[1][1] + board[1][2];

		for (int i = 2; i <= n; i++)
		{
			if (i == 2)
			{
				d[i][0] = d[i - 1][1] + board[i][0];
				d[i][1] = min({ d[i - 1][1], d[i - 1][2], d[i][0] }) + board[i][1];
			}
			else
			{
				d[i][0] = min(d[i - 1][0], d[i - 1][1]) + board[i][0];
				d[i][1] = min({ d[i - 1][0], d[i - 1][1], d[i - 1][2], d[i][0] }) + board[i][1];
			}
			
			d[i][2] = min({ d[i - 1][1], d[i - 1][2], d[i][1] }) + board[i][2];
		}

		cout << test << ". " << d[n][1] << '\n';
	}
}