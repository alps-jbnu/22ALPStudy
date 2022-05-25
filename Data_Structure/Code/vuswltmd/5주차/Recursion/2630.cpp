#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

int paper[128][128];
int cnt[2];
int N;

bool check(int x, int y, int n)
{
	for (int i = x; i < x + n; i++)
	{
		for (int j = y; j < y + n; j++)
		{
			if (paper[i][j] != paper[x][y])
				return false;
		}
	}

	cnt[paper[x][y]]++;
	return true;
}

void func(int x, int y, int n)
{
	if( check(x, y, n) )
	{
		return;
	}

	int val = n / 2;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			func(x + i * val, y + j * val, val);

}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> paper[i][j];
		}
	}

	func(0, 0, N);

	for (int i = 0; i < 2; i++)
	{
		cout << cnt[i] << '\n';
	}
}