#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 2188
using namespace std;

int N;
int result[3];
int arr[MAX][MAX];

bool Check(int row, int column, int n)
{
	int idx = arr[row][column];

	for (int i = row; i < row + n; i++)
	{
		for (int j = column; j < column + n; j++)
		{
			if (idx != arr[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

void Solve(int row, int column, int n)
{
	if (Check(row, column, n))
	{
		result[arr[row][column]]++;
	}
	else
	{
		int size = n / 3;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				Solve(row + size * i, column + size * j, size);
			}
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int num;
			cin >> num;
			num++;
			arr[i][j] = num;
		}
	}

	Solve(0, 0, N);
	cout << result[0] << " " << result[1] << " " << result[2];

	return 0;
}