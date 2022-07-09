#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

int paper[2200][2200];
int cnt[3];

bool check(int x, int y, int n)
{
	for (int i = x; i < x+n; i++)
	{
		for (int j = y; j < y+n; j++)
		{
			if (paper[i][j] != paper[x][y])
				return false;
				
		}
	}
	return true;
}

void func(int x, int y, int n)
{
	if (check(x, y, n) == true)
	{
		cnt[paper[x][y] + 1] += 1;
		return;
	}

	int val = n / 3;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			func(x + i * val, y + val * j, val);
		}
	}
}

int main()
{
	int n;

	cin >> n;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> paper[i][j];
		}
	}

	func(0, 0, n);

	for (int i = 0; i < 3; i++)
	{
		cout << cnt[i] << "\n";
	}
}