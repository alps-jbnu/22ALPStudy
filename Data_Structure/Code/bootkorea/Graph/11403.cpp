#include <iostream>
using namespace std;

int N;
int arr[101][101];

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][k] && arr[k][j])
				{
					arr[i][j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}