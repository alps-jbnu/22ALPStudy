#include <bits/stdc++.h>
using namespace std;

int N, result = 0;
int arr[1000 + 1];
vector<int> vec;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);

	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			vec.push_back(arr[i] + arr[j]);
		}
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (binary_search(vec.begin(), vec.end(), arr[j] - arr[i]))
			{
				result = max(result, arr[j]);
			}
		}
	}
	cout << result;

	return 0;
}