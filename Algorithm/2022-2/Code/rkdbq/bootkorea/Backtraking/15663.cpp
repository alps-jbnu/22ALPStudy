#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int arr[9];
bool Visited[0];
vector<int> vec;

void Solve(int x)
{
	if (x == M)
	{
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << " ";
		}
		cout << "\n";
		return;
	}

	int num = 0;
	for (int i = 0; i < N; i++)
	{
		if (Visited[i] == true || arr[i] == num) // 예외처리
		{
			continue;
		}

		Visited[i] = true;
		num = arr[i];
		vec.push_back(arr[i]);

		Solve(x + 1); // 재귀를 통해 과정 추적

		Visited[i] = false;

		vec.pop_back();
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

	Solve(0);

	return 0;
}