#include <iostream>
#include <cstring>
using namespace std;

int N;
int arr[65][65];
string str;

int Solve(int N, int y, int x)
{
	if (N == 1)
	{
		cout << arr[y][x];
		return 0;
	}

	int temp = arr[y][x];
	int num = N / 2;

	for (int i = y; i < y + N; i++)
	{
		for (int j = x; j < x + N; j++)
		{
			if (temp != arr[i][j])
			{
				cout << "(";
				Solve(num, y, x);
				Solve(num, y, x + num);
				Solve(num, y + num, x);
				Solve(num, y + num, x + num);
				cout << ")";
				return 0;
			}
		}
	}
	cout << temp;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;

		for (int j = 0; j < N; j++)
		{
			arr[i][j] = str[j] - '0';
		}
	}

	Solve(N, 0, 0);

	return 0;
}