#include <iostream>
#include <vector>
using namespace std;

int N;
long long arr[91];

int main()
{
	cin >> N;
	arr[1] = 1; arr[2] = 1;

	for (int i = 3; i <= N; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	cout << arr[N];

	return 0;
}