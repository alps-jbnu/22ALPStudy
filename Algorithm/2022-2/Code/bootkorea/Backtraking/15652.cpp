#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[9];

void Solve(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = (cnt == 0) ? 1 : arr[cnt - 1]; i <= N; i++)
	{
		arr[cnt] = i;
		Solve(cnt + 1);
	}
}

int main()
{
	cin >> N >> M;

	Solve(0);

	return 0;
}