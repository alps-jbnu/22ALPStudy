#include <iostream>
#include <algorithm>
#define MAX 1000000 + 1
using namespace std;

int N, arr[MAX];

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N, greater<>());

	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << "\n";
	}

	return 0;
}