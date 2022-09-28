#include <bits/stdc++.h>
#define ll long long
const int MAX = 100000 + 1;
using namespace std;

int N;
int cur = 0, result = 0;
int arr[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N); result = arr[N - 1];

	for (int i = N - 1; i >= 0; i--)
	{
		cur = arr[i] * (N - i);
		if (result <= cur) result = cur;
	}
	cout << result;

	return 0;
}