#include <iostream>
using namespace std;

int N, S, count = 0;
int arr[21];

void Solve(int idx, int sum)
{
	sum += arr[idx];

	if (idx >= N) return;

	if (sum == S)
	{
		count++;
	}

	Solve(idx + 1, sum - arr[idx]);
	Solve(idx + 1, sum);
}

int main()
{
	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	Solve(0, 0);

	cout << count;

	return 0;
}