// 이 문제는 솔직히 다시 풀자
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int arr[9], result[9];

void Solve(int cnt, int start)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	int num = 0;
	for (int i = start; i < N; i++)
	{
		if (num != arr[i])
		{
			result[cnt] = arr[i];
			num = result[cnt];
			Solve(cnt + 1, i);
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];

	}
	sort(arr, arr + N);

	Solve(0, 0);

	return 0;
}