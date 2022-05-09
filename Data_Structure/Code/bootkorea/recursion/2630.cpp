#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int count_w = 0, count_b = 0;
int arr[128][128];

void function(int x, int y, int N)
{
	int temp = 0;
	for (int i = x; i < x + N; i++)
	{
		for (int j = y; j < y + N; j++)
		{
			if (arr[i][j] == 1)
			{
				temp++;
			}
		}
	}

	if (temp == 0)
	{
		count_w++;
	}
	else if (temp == N * N)
	{
		count_b++;
	}
	else
	{
		function(x, y, N / 2);
		function(x + (N / 2), y, N / 2);
		function(x, y + (N / 2), N / 2);
		function(x + (N / 2), y + (N / 2), N / 2);
	}
	return;
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie();

	int N;
	cin >> N;

	memset(arr, false, sizeof(N));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	function(0, 0, N);

	cout << count_w << endl;
	cout << count_b << endl;
	return 0;
}