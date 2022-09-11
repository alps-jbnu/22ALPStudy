#include <iostream>
#define MAX 1000001
using namespace std;

int N;
int DP[MAX], arr[MAX];

int Solve(int num)
{
	DP[1] = 0;
	arr[1] = -1;

	for (int i = 2; i <= num; i++)
	{
		// -1을 하는 케이스
		DP[i] = DP[i - 1] + 1;
		arr[i] = i - 1;

		// 2로 나누는 케이스
		if (i % 2 == 0 && DP[i] > DP[i / 2] + 1)
		{
			DP[i] = DP[i / 2] + 1;
			arr[i] = i / 2;
		}

		// 3으로 나누는 케이스
		if (i % 3 == 0 && DP[i] > DP[i / 3] + 1)
		{
			DP[i] = DP[i / 3] + 1;
			arr[i] = i / 3;
		}
	}

	return DP[num];
}

int main()
{
	cin >> N;
	cout << Solve(N) << "\n";

	while (N != -1)
	{
		cout << N << " ";
		N = arr[N];
	}

	return 0;
}