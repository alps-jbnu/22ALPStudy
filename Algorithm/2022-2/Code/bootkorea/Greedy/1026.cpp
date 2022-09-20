#include <iostream>
#include <algorithm>
#define MAX 100 + 1
using namespace std;

bool compare(int x, int y)
{
	return y < x;
}

int N, result = 0;
int A[MAX], B[MAX], arr[MAX];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> B[i];
	}
	sort(A, A + N);
	sort(B, B + N, compare);

	for (int i = 0; i < N; i++)
	{
		result += A[i] * B[i];
	}
	cout << result;

	return 0;
}