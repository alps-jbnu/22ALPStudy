#include <iostream>
#include <algorithm>
using namespace std;

int N, result = 0;
int arr[16], pay[16];

void Solve(int day, int sum, int num)
{
	if (day == N)
	{
		result = max(result, sum);
		return;
	}
	else if (day > N)
	{
		result = max(result, sum - num);
		return;
	}

	for (int i = day + arr[day]; i < N + arr[day]; i++)
	{
		Solve(i, sum + pay[day], pay[day]);
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i] >> pay[i];
	}

	for (int i = 0; i < N; i++)
	{
		Solve(i, 0, 0);
	}

	cout << result;

	return 0;
}